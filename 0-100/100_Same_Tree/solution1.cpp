/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 解法一：递归遍历
 *        判断两棵二叉树是否相等，则需要判断每一棵子二叉树的根，左，右节点是否相等。
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //如果某节点为空指针，则判断是否两棵树该处节点都是空指针
        if(p== nullptr || q== nullptr)
            return p==q;
        //判断，根，左，右是否都相等
        return p->val==q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};