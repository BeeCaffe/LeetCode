/***********************************************************************************************************************
 * Created by caffe on 2019/10/29.
 * 题干：
 *      Given a binary tree, find its minimum depth.
 *      The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *      Note: A leaf is a node with no children.
 * 解法一：递归法
 *      直接递归求二叉树的深度,类似与maxDepth的求法，但是需要注意一个问题，那就是当root左子树和右子树某一个返回0而另一个不为0的时候，说明
 *      存在一个nullptr的节点，但这个节点不是叶子节点，因此这时的0不应该再算作树的最小高度了。
 * 时间复杂度：O（log2n）
 * 空间复杂度：O（1）
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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftDp=minDepth(root->left);
        int rightDp=minDepth(root->right);
        if(leftDp==0 && rightDp!=0) return rightDp+1;
        if(leftDp!=0 && rightDp==0) return leftDp+1;
        return 1+min(leftDp,rightDp);
    }
};