/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 题干：
 *      Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then
 *      right to left for the next level and alternate between).
 * 解法一：层次遍历变形
 *      Z形遍历是层次遍历的一个变形，不同点在于，当上一次从左到右遍历时，下一层将改为从右到左遍历。具体的方法是，设置一个参数level记录遍历的
 *      层数，从1开始，当为偶数时将该层的遍历次序翻转一次即可。
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode* > que;
        que.push(root);
        int level=1;
        while(!que.empty()){
            vector<int> tmp;
            for(int i=que.size()-1;i>=0;--i){
                TreeNode *node=que.front();
                que.pop();
                tmp.push_back(node->val);
                if(node->left!=nullptr) que.push(node->left);
                if(node->right!=nullptr) que.push(node->right);
            }
            if(level%2==0) reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
            ++level;
        }
        return res;
    }
};