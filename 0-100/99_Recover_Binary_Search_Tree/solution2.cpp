/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 解法二：
 *      由于二叉查找树通过中序遍历的结果是有序的，因此我们只需要记录中序遍历的前一个节点，将它与当前节点值比较，如果不是升序的，则表示这里是
 *      错误位置，采用两个指针first和second分别指向顺序错误的节点，用指针pre指向中序遍历的上一个节点。
 *      1.中序遍历二叉查找树，pre，first，second分别记录中序遍历前一个节点，错误节点一，错误节点二
 *      2.找到错误节点1,2之后，将其交换。
 * 时间复杂度：由于要递归遍历二叉树，时间复杂度为O（n）.
 * 空间复杂度：O（1）.
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
    TreeNode *pre=nullptr,*first=nullptr,*second=nullptr;
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }

    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        if(pre==nullptr) pre=root;
        else{
            if(pre->val > root->val){
                if(first==nullptr) first=pre;
                second=root;
            }
            pre=root;
        }
        inorder(root->right);
    }
};