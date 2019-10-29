/***********************************************************************************************************************
 * Created by caffe on 2019/10/29.
 * 题干：
 *      Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right,
 *      level by level from leaf to root).
 * 解法一：暴力法
 *      按照一般顺序层次遍历二叉树，最后将结果reverse
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> tmp;
            for(int i=que.size()-1;i>=0;--i){
                TreeNode *node=que.front();
                que.pop();
                tmp.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};