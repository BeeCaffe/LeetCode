/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 解法四：采用Morris算法（暂未实现）
 *        采用Morris算法遍历二叉查找树，并如方法二，三记录错误节点的位置，最后交换。
 * 时间复杂度：O（n）
 * 空间复杂度：O（1）
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
    void recoverTree(TreeNode* root) {
        TreeNode *first = NULL, *second = NULL, *parent = NULL;
        TreeNode *cur, *pre;
        cur = root;
        while (cur) {
            if (!cur->left) {
                if (parent && parent->val > cur->val) {
                    if (!first) first = parent;
                    second = cur;
                }
                parent = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    if (parent->val > cur->val) {
                        if (!first) first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};