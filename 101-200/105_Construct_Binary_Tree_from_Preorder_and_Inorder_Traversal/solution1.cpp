/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 题干：
 *      Given preorder and inorder traversal of a tree, construct the binary tree.
 *      Note:You may assume that duplicates do not exist in the tree.For example, given
 * 解法一：递归法
 *      由于先序遍历的第一个节点是根节点，而且对于每一个子树都为根。中序遍历的根节点恰好在中间，左右两边分别对应左右子树。因此，通过先序遍历
 *      和中序遍历的结果来构造二叉树的方法是：
 *      1.依次遍历先序遍历结果中的节点
 *      2.在中序遍历的结果中找到对应的位置，其左边就是最后结果的左树，右边是右树。
 *      3.递归建立左子树和右子树，递归时对于先序遍历的结果序列，前面部分始终是根节点的左子树，右边部分是根节点的右子树，节点个数恰好等于中序
 *      遍历对应根节点左右两边的节点数目。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0)
            return nullptr;
        return createTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* createTree(vector<int>& preorder,int prebeg,int preend,vector<int>& inorder,int inbeg,int inend){
        if(prebeg>preend || inbeg>inend) return nullptr;
        int root_val=preorder[prebeg];
        int root_index=0;
        for(int i=inbeg;i<=inend;++i){
            if(inorder[i]==root_val){
                root_index=i;
                break;
            }
        }

        int len=root_index-inbeg;
        TreeNode *root=new TreeNode(root_val);
        root->left=createTree(preorder,prebeg+1,prebeg+len,inorder,inbeg,root_index-1);
        root->right=createTree(preorder,prebeg+len+1,preend,inorder,root_index+1,inend);
        return root;
    }
};