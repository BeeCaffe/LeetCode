/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 题干：
 *      Given a binary tree, find its maximum depth.The maximum depth is the number of nodes along the longest path from
 *      the root node down to the farthest leaf node.Note: A leaf is a node with no children.
 * 解法一：层次遍历记录层数
 *      通过层次遍历来记录二叉树的层数，最后返回二叉树的最大深度。
 * 时间复杂度：由于要遍历二叉树，因此是O（n）
 * 空间复杂度：层次遍历需要准备一个队列，因此是O（n）
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
        if(!root) return 0;
        int level=0;
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty()){
            for(int i=que.size()-1;i>=0;--i){
                TreeNode *node=que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ++level;
        }
        return level;
    }
};