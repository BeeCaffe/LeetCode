/***********************************************************************************************************************
 * Created by caffe on 2019/10/29.
 * 题干：
 *      Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 *      For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two
 *      subtrees ofevery node never differ by more than 1.
 * 解法一：直接法
 *      直接将链表转成数组，然后用第108题一样的方法解决问题。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 **********************************************************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return {};
        ListNode *ptr=head;
        vector<int> nums;
        while(ptr!=nullptr){
            nums.push_back(ptr->val);
            ptr=ptr->next;
        }
        return createTree(nums,0,nums.size()-1);
    }
    TreeNode *createTree(vector<int> &nums,int beg,int end){
        if(beg>end) return nullptr;
        int mid=beg+(end-beg)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=createTree(nums,beg,mid-1);
        root->right=createTree(nums,mid+1,end);
        return root;
    }
};