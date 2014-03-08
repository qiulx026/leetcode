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
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *bighead=new ListNode(0);
        ListNode *temp;
        while(head!=NULL){
            temp=head;
            head=head->next;
            myinsert(bighead,temp);
        }
        return bighead->next;
    }
    void myinsert(ListNode* bighead, ListNode *temp){
        ListNode *pre,*cur;
        pre=bighead;
        cur=bighead->next;
        while(cur!=NULL&&cur->val<temp->val){
            pre=cur;
            cur=cur->next;
        }
        pre->next=temp;
        temp->next=cur;
    }
};