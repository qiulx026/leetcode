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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *h=new ListNode(0);
        h->next=head;
        ListNode *pre=h;
        ListNode *cur=head;
        ListNode *next=head->next;
        while(next!=NULL){
            if(cur->val!=next->val){
                pre=cur;
                cur=next;
                next=next->next;
                continue;
            }
            else{
                while(next!=NULL){
                    if(cur->val==next->val){
                        next=next->next;
                        continue;
                    }
                    else break;
                }
                if(next==NULL) pre->next=NULL;
                else {
                    pre->next=next;
                    cur=next;
                    next=next->next;
                }
            }
            
            
        }
        return h->next;
    }
};