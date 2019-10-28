/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 题干：
 *      Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * 解法一：迭代法
 *       二叉树的层次遍历方法是准备一个队列，先将根节点入队，出队时将每个节点的左孩子和又孩子入对（左右孩子非空时）。
 **********************************************************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)
            return {};
        TreeNode* cur;
        vector<vector<int>> res;
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty()){
            vector<int> tmp;
            for(int i=que.size()-1;i>=0;--i){
                TreeNode* node=que.front();
                que.pop();
                tmp.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};