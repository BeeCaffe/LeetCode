/***********************************************************************************************************************
 * Created by caffe on 2019/10/29.
 * 题干：
 *      Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values
 *      along the path equals the given sum.
 *      Note: A leaf is a node with no children.
 * 解法一：DFS遍历
 *      深度优先遍历二叉树，求解每一路的和，看是否与目标值相同。即从根节点出发，搜索每一个到根节点的路径，然后判断和是否为sum。
 *
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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr) return false;
        if(root->left==nullptr && root->right==nullptr && root->val==sum) return true;
        return hasPathSum(root->left,sum-root->val) || hasPathSum(root->right,sum-root->val);
    }
};