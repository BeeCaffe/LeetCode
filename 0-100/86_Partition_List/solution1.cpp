//
// Author: BeeCaffe.
// GitHub: https://github.com/BeeCaffe/BeeCaffe.github.io
//
/**
 * @name link list
 * @brief
 *      1.set a flag to record whether has met node's value bigger or equal to x;
 *      2.travel the linked list,if value is smaller than x and flag=false,keep go.
 *      3.if met first value bigger than or equal to x,set flag to true,and record the location.
 *      4.if flag is true and value is less than x, insert it to the recorded location.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *res=new ListNode(0);
        res->next=head;
        ListNode *cur=head,*pre=res;
        ListNode *insert_pre=nullptr,*insert_cur=nullptr;
        bool flag=false;
        while(cur!=NULL){
            if(cur->val<x && flag==false){
                pre=cur;
                cur=cur->next;
            }else if(cur->val>=x && flag==false){
                insert_pre=pre;
                insert_cur=cur;
                flag=true;
                pre=cur;
                cur=cur->next;
            }else if(cur->val<x && flag==true){
                pre->next=cur->next;
                cur->next=insert_cur;
                insert_pre->next=cur;
                cur=pre->next;
                insert_pre=insert_pre->next;
            }else{
                pre=cur;
                cur=cur->next;
            }
        }
        return res->next;
    }
};