/***********************************************************************************************************************
 * Created by caffe on 2019/10/31.
 * 题干：
        Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

        An example is the root-to-leaf path 1->2->3 which represents the number 123.

        Find the total sum of all root-to-leaf numbers.

        Note: A leaf is a node with no children.
 * 解法一：DFS（深度优先搜索递归算法）
        想要查找到所有根到叶子节点的和，实际上最简单的想法就是找到根到所有叶子的路径，并求出所有路径和再相加。这实际上是一个深度优先遍历的过
        程，而深度优先遍历和树的先序遍历很类似。使用递归算法的时候应该注意，是递归到叶子节点的时候计算和并返回，而不是节点为空的时候，如果采
        取后者的策略，那么就会造成重复计算，因为一个叶子节点的左，右孩子都会为空。
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
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        vector<int> path;
        int sum=0;
        sumTree(root,path,sum);
        return sum;
    }
    void sumTree(TreeNode* root,vector<int> &path,int &sum){
        if(root==nullptr) return;
        if(root->left==nullptr&&root->right==nullptr){
            path.push_back(root->val);
            int tmp=0;
            for(int i=0;i<path.size();++i){
                tmp=tmp*10+path[i];
            }
            sum+=tmp;
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        sumTree(root->left,path,sum);
        sumTree(root->right,path,sum);
        path.pop_back();
    }
};