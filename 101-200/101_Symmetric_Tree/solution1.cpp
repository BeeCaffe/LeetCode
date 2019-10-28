/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 题干：
 *      Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 解法1：
 *      采用和100题（SameTree）类似的方法，是判断二叉树是否对称应该判断，根节点，左子树的左边和右子树的右边，左子树的右边和右子树的左边是否
 *      相等即可。
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
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return helper(root->left,root->right);
    }

    bool helper(TreeNode* left,TreeNode* right){
        if(left==nullptr || right==nullptr)
            return left==right;
        return left->val==right->val && helper(left->left,right->right) &&helper(left->right,right->left);
    }
};