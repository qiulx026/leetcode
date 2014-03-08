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
    ListNode *reverseKGroup(ListNode *head, int k) {
    if(k==1||head==NULL) return head;
    int length=0;
    ListNode *temp=head;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    int iter=length/k;
    ListNode *bighead= new ListNode(0);
    ListNode *h=bighead, *cur, *pre, *next;
    bighead->next=head;
    for(int i=0;i<iter;i++){
        pre=h->next;
        cur=pre->next;
        next=cur->next;
        for(int j=0;j<k-1;j++){
            cur->next=pre;
            pre=cur;
            cur=next;
            if(next!=NULL) next=next->next;
        }
        temp=h->next;
        h->next->next=cur;
        h->next=pre;
        h=temp;
    }
    return bighead->next;
    }
};