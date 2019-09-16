//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * @name link list
 * @brief very simple,if cur->val equal to next->val,delete next.
 *        the time complexity is O(n) the space complexity is O(1).
 */
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return head;
        ListNode *p_cur=head,*p_next=head->next;
        while(p_next!=NULL){
            if(p_cur->val==p_next->val){
                p_cur->next=p_next->next;
                p_next=p_cur->next;
            }else{
                p_cur=p_next;
                p_next=p_next->next;
            }
        }
        return head;
    }
};