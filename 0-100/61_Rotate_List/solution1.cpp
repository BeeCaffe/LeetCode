//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * 直接暴力解决：
 *  1.先求出整个链表长度，并且记录下最后一个节点指针。
 *  2.算出链表应该从什么地方截断,loc=len-k%len
 *  3.从该位置截断链表,并且接到前面去
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int len=1;
        ListNode *p=head,*pend=NULL;
        while(p->next!=NULL){
            len++;
            p=p->next;
        }
        pend=p;
        p=head;
        int loc=len - k%len-1;
        for(int i=loc;i>0;i--){
            p=p->next;
        }
        ListNode *temp=p->next;
        if(temp!=NULL){
            p->next=NULL;
            pend->next=head;
            head=temp;
        }
        return head;
    }
};