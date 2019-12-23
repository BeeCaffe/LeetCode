//
// Created by caffe on 2019/12/18.
//
/*
 * 2. 两数相加
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
   如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
   您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 */

/**
 * solution 1 : 单链表
 * 时间复杂度：O（n）
 * 空间复杂度：O(n)
 */
//执行用时 :36 ms, 在所有 cpp 提交中击败了36.32%的用户
//内存消耗 :10.2 MB, 在所有 cpp 提交中击败了91.10%的用户
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *pre=head,*cur=head;
        int movebit=0;
        while(l1!=NULL&&l2!=NULL){
            int sum = l1->val+l2->val+movebit;
            cur = new ListNode(sum%10);
            movebit=sum/10;
            pre->next=cur;
            pre=cur;
            l1=l1->next;l2=l2->next;
        }
        while(l1!=NULL){
            int sum=l1->val+movebit;
            cur = new ListNode(sum%10);
            movebit = sum/10;
            pre->next = cur;
            pre=cur;
            l1=l1->next;
        }
        while(l2!=NULL){
            int sum=l2->val + movebit;
            cur = new ListNode(sum%10);
            movebit = sum/10;
            pre->next=cur;
            pre=cur;
            l2=l2->next;
        }
        if(movebit!=0) pre->next=new ListNode(movebit);
        return head->next;
    }
};