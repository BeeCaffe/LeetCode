/***********************************************************************************************************************
 * Created by caffe on 2019/10/29.
 * 题干：
 *      Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 *      For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two
 *      subtrees of every node never differ by more than 1.
 * 解法一：递归法
 *      二叉搜索树的特点是左<根<右，因此根节点一定会是有序序列的中间那个元素，构建湾根节点之后，我们就可以递归地构造左右子树。
 *      1.找到数组的中间元素，构造根节点
 *      2.递归构造左右子树
 * 时间复杂度：O（log2n）
 * 空间复杂度：O（n）
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return {};
        return createTree(nums,0,nums.size()-1);
    }

    TreeNode *createTree(vector<int>& nums,int beg,int end){
        if(beg>end) return nullptr;
        int mid=beg+(end-beg)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=createTree(nums,beg,mid-1);
        root->right=createTree(nums,mid+1,end);
        return root;
    }
};