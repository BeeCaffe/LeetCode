/***********************************************************************************************************************
 * Created by caffe on 2019/10/29.
 * 题干：
 *      Given inorder and postorder traversal of a tree, construct the binary tree.
 *      Note:You may assume that duplicates do not exist in the tree.For example, given
 * 解法一：递归法
 *      由于中序遍历的顺序是左根右，后序遍历的顺序是左右根，因此，可以先通过后序遍历找到根节点，再从中序遍历中找到根节点的左右子树，建立二叉
 *      树。
 *      1.通过后序遍历找到根节点
 *      2.通过中序遍历找到左右子树
 *      3.递归建立二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0) return nullptr;
        return createTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }

    TreeNode *createTree(vector<int> &inorder,int inbeg,int inend,vector<int> &postorder,int postbeg,int postend){
        if(inbeg>inend || postbeg>postend) return nullptr;
        int root_val=postorder[postend];
        int root_index=0;
        for(int i=inbeg;i<=inend;++i){
            if(root_val==inorder[i]){
                root_index=i;
                break;
            }
        }
        int len=root_index-inbeg;
        TreeNode *root=new TreeNode(root_val);
        root->left=createTree(inorder,inbeg,root_index-1,postorder,postbeg,postbeg+len-1);
        root->right=createTree(inorder,root_index+1,inend,postorder,postbeg+len,postend-1);
        return root;
    }
};