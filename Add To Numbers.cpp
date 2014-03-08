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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int n=0,flag=0;
        ListNode *l=new ListNode(0);
        ListNode *ll;
		ll=l;
        while((l1!=NULL)&&(l2!=NULL)){
            l->next=new ListNode(0);l=l->next;
            n=l1->val+l2->val+flag;
            if(n>9) {n=n%10;flag=1;}
            else flag=0;
            l->val=n;
			l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            l->next=new ListNode(0);l=l->next;
            n=l1->val+flag;
            if(n>9) {n=n%10;flag=1;}
            else flag=0;
            l->val=n;
            l1=l1->next;
        }
        while(l2!=NULL){
            l->next=new ListNode(0);l=l->next;
            n=l2->val+flag;
            if(n>9) {n=n%10;flag=1;}
            else flag=0;
            l->val=n;
            l2=l2->next;
        }
		if(flag==1) l->next=new ListNode(1);
        return ll->next;
    }
};