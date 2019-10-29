/***********************************************************************************************************************
 * Created by caffe on 2019/10/29.
 * 题干:
 *      Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *      Note: A leaf is a node with no children.
 * 解法一：DFS，深度优先搜索（递归形式）
 *      利用深度优先搜索遍历每一条路径，将路径之和等于sum的路径记录下来。
 * 时间复杂度：O（log2n）
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr) return {};
        vector<vector<int>> res;
        vector<int> tmp;
        searchPath(res,tmp,root,sum);
        return res;
    }

    void searchPath(vector<vector<int>> &res,vector<int> &tmp,TreeNode *root,int sum){
        if(root==nullptr) return ;
        tmp.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr && root->val==sum){
            res.push_back(tmp);
        }
        searchPath(res,tmp,root->left,sum-root->val);
        searchPath(res,tmp,root->right,sum-root->val);
        tmp.pop_back();
    }
};