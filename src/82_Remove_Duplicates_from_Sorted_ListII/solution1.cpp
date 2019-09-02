//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//

/**
 * @name link list
 * @brief you may need to set three pointer to solve this problem, pre,cur and next.
 *        you'd better build a new node as pre and return the pre->next as the ans,
 *        the time complexity is O(n), the space complexity is O(1).
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
        ListNode *pre=new ListNode(0),*cur=head,*nxt=head->next;
        ListNode *res=pre;
        pre->next=head;
        while(nxt!=NULL){
            if(cur->val==nxt->val){
                while(nxt!=NULL&&cur->val==nxt->val) nxt=nxt->next;
                pre->next=nxt;
                cur=nxt;
                if(nxt!=NULL) nxt=nxt->next;
                else break;
            }else{
                pre=cur;
                cur=nxt;
                nxt=nxt->next;
            }
        }
        return res->next;
    }
};