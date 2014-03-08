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
    void reorderList(ListNode *head) {
        if(head==NULL||head->next==NULL) return;
        ListNode *slow,*fast;
        ListNode *first,*second;
        slow=head,fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        first=head;
        second=slow->next;
        slow->next=NULL;
        second=reverse(second);
        merge(first,second);
    }
    ListNode* reverse(ListNode *head){
        if(head->next==NULL) return head;
        ListNode *cur,*pre,*temp;
        pre=NULL;
        cur=head;
        while(cur->next!=NULL){
            temp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=temp;
        }
        cur->next=pre;
        head=cur;
    }
    void merge(ListNode *f,ListNode *s){
        ListNode *f1=f,*s1=s,*temp1,*temp2;
        while(f1&&s1){
            temp1=f1->next;
            temp2=s1->next;
            f1->next=s1;
            s1->next=temp1;
            f1=temp1;
            s1=temp2;
        }
    }
};