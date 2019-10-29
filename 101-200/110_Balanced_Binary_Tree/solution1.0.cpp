/***********************************************************************************************************************
 *
 * Created by caffe on 2019/10/29.
 * 题干：
 *      Given a binary tree, determine if it is height-balanced.
 *      For this problem, a height-balanced binary tree is defined as:
 *      a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 * 解法一：递归法
 *      1.分别求出左，右子树的最大高度
 *      2.比较左右子树的深度差是否大于1
 *      3.递归得判断每一个节点的左右子树
 *  时间复杂度：O（log2n）
 *  空间复杂度：O（1）
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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        else{
            int leftDepth=maxDepth(root->left);
            int rightDepth=maxDepth(root->right);
            if(leftDepth-rightDepth>1 || leftDepth-rightDepth<-1) return false;
            else return isBalanced(root->left)&&isBalanced(root->right);
        }

    }
    int maxDepth(TreeNode *root){
        if(root==nullptr) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};