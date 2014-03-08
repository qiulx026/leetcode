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
    ListNode *swapPairs(ListNode *head) {
        ListNode *h= new ListNode(0);
        ListNode *pre=h;
        h->next=head;
        while(pre->next!=NULL&&pre->next->next!=NULL){
            swapf(pre);
            pre=pre->next->next;
        }
        return h->next;
    }
    void swapf(ListNode *pre){
        ListNode *temp;
        temp=pre->next;
        pre->next=temp->next;
        temp->next=pre->next->next;
        pre->next->next=temp;
    }
};