/***********************************************************************************************************************
 * Created by caffe on 2019/10/29.
 * 解法二：直接法
 *        直接得到链表的中间位置，然后递归建立二叉查找树，具体得到的方法是，声明两个链表指针，指向开始位置，一个每次走过一个节点，另一个每次
 *        走过两个节点，这样当快的节点到到链表尾端的时候，慢的指针刚好到达中间位置。
 * 时间复杂度：O（（n/2）log2n）
 * 空间复杂度：O（1）
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
        if(head==nullptr) return nullptr;
        return createTree(head,nullptr);
    }
    TreeNode* createTree(ListNode *head,ListNode *end){
        if(head==end) return nullptr;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=end&&fast->next!=end){
            fast=fast->next->next;
            slow=slow->next;
        }
        TreeNode *root=new TreeNode(slow->val);
        root->left=createTree(head,slow);
        root->right=createTree(slow->next,end);
        return root;
    }
};