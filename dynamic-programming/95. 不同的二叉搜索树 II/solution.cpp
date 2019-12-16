/***********************************************************************************************************************
 * Created by caffe on 2019/12/12.
 * 95. 不同的二叉搜索树 II
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 **********************************************************************************************************************/
/**
 * solution 1 : 递归法
 * 时间复杂度：O（n4/n1/2）
 * 空间复杂度：O（n4/n1/2）
 */
//执行用时 :24 ms, 在所有 cpp 提交中击败了79.48% 的用户
//内存消耗 :17.2 MB, 在所有 cpp 提交中击败了45.12%的用户
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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return generate_trees(1,n);
    }
    vector<TreeNode* > generate_trees(int left,int right){
        vector<TreeNode* > all_trees;
        if(left>right){
            all_trees.push_back(nullptr);
            return all_trees;
        }
        for(int i=left;i<=right;++i){
            vector<TreeNode* > left_tree=generate_trees(left,i-1);
            vector<TreeNode* > right_tree=generate_trees(i+1,right);
            for(TreeNode* l:left_tree){
                for(TreeNode* r:right_tree){
                    TreeNode* cur_tree=new TreeNode(i);
                    cur_tree->left=l;
                    cur_tree->right=r;
                    all_trees.push_back(cur_tree);
                }
            }
        }
        return all_trees;
    }

};