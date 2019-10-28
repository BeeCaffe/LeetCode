/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 解法二：递归法
 *      1.当节点为nullptr时，说明到达了最下面一个，返回0
 *      2.返回左右子树的最大高度
 * 时间复杂度：O（log2（n））
 * 空间度杂度：O（1）
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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NUxLL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root==nullptr ? 0:1+max(maxDepth(root->left),maxDepth(root->right));
    }
};