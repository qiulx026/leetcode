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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n) return head;
        ListNode *p,*head1,*curp,*nextp,*nextpp;
        head1=new ListNode(0);
        head1->next=head;
        p=head;
        head=head1;
        n=n-m;
        while(p->next!=NULL&&m-1>0){
            head1=p;
            p=p->next;
            m--;
        }
        curp=p;
        nextp=p->next;
        while(nextp!=NULL&&n>0){
            nextpp=nextp->next;
            nextp->next=curp;
            
            curp=nextp;
            nextp=nextpp;
            n--;
        }
        head1->next->next=nextp;
        head1->next=curp;
        return head->next;
    }
};