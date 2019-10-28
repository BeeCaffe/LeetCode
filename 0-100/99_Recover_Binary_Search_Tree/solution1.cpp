/***********************************************************************************************************************
 * Created by caffe on 2019/10/28.
 * 题干：
 *      Two elements of a binary search tree (BST) are swapped by mistake.Recover the tree without changing its structure.
 * 解法一：暴力解法
 *      这种算法的思路比较简单，将所有的节点值重新排序，再赋值给二叉排序树，这样一来对于任意个数的乱序节点都可以
 *      用这个算法来解决。
 *      1.将二叉查找树的节点和节点值分别存储在两个vector里面
 *      2.对二叉查找树的节点值进行排序
 *      3.将排序后的值赋值给二叉查找树的节点
 * 时间复杂度：O（n）
 * 空间复杂度：O（2n）
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
        vector<TreeNode *> node_list;
        vector<int> val_list;
        inorder(root,node_list,val_list);
        sort(val_list.begin(),val_list.end());
        for(int i=0;i<val_list.size();++i){
            node_list[i]->val=val_list[i];
        }
    }

    void inorder(TreeNode* root,vector<TreeNode* > &node_list,vector<int> &val_list){
        if(root==nullptr) return;
        inorder(root->left,node_list,val_list);
        node_list.push_back(root);
        val_list.push_back(root->val);
        inorder(root->right,node_list,val_list);
    }
};