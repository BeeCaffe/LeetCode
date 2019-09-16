/***********************************************************************************************************************
 * Author: BeeCaffe.
 * GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
 *
***********************************************************************************************************************/

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *Cur=head,*Pre=NULL,*Next=NULL;
        ListNode *m_pre=NULL,*m_p=NULL;
        size_t count=1;
        while(Cur!=NULL){
            if(count<m){
                Pre=Cur;
                Cur=Cur->next;
            }else if(count>=m&&count<=n){
                if(count==m){
                    m_pre=Pre;
                    m_p=Cur;
                }
                Next=Cur->next;
                Cur->next=Pre;
                Pre=Cur;
                Cur=Next;
                if(count==n){
                    if(m_pre!=NULL) m_pre->next=Pre;
                    else head=Pre;
                    if(m_p!=NULL) m_p->next=Cur;
                }
            }else break;
            count++;
        }
        return head;
    }
};