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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p,*q=head,*headz;
        headz=new ListNode(0);
        headz->next=head;
        p=headz;
        while(n>0){
            q=q->next;
            n--;
        }
        while(q!=NULL){
            p=p->next;
            q=q->next;
        }
        p->next=p->next->next;
        return headz->next;
    }
};