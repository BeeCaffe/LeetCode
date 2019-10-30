/***********************************************************************************************************************
 * Created by caffe on 2019/10/29.
 * 题干：
 *      Given a binary tree, flatten it to a linked list in-place.
 * 解法一：递归法
 *        将排好序的左子树插入根节点和右子树之间。具体做法是将左子树先挂在右子树上，然后再遍历到现在右子树最下面的一个节点，然后再把右子树重
 *        新挂上去而结束条件就是根节点为nullptr
 * 时间复杂度：
 *          1）最坏情况：全部节点在左边时，O（n2）
 *          2）平均情况：递归时间复杂度T（n）=2T（n/2）+O（log）
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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        flatten(root->left);
        flatten(root->right);

        TreeNode *save_right=root->right;
        root->right=root->left;
        TreeNode *cur=root;
        while(cur->right!=nullptr) cur=cur->right;
        cur->right=save_right;
        root->left=nullptr;
    }
};