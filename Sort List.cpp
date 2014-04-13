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
    ListNode *sortList(ListNode *head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *bighead=new ListNode(0);
        ListNode *right,*left;
        bighead->next=head;
        right=bighead;
        left=bighead;
        while(left->next!=NULL&&left->next->next!=NULL){
            right=right->next;
            left=left->next->next;
        }
        left=right->next;
        right->next=NULL;
        right=bighead->next;
        right=sortList(right);
        left=sortList(left);
        head=merge(right,left);
        return head;
    }
    ListNode * merge(ListNode *right, ListNode *left){
        ListNode *bighead=new ListNode(0);
        ListNode *temp=bighead;
        while(right!=NULL&&left!=NULL){
            if(right->val<left->val){
                temp->next=right;
                right=right->next;
                temp=temp->next;
            }
            else{
                temp->next=left;
                left=left->next;
                temp=temp->next;
            }
        }
        while(right!=NULL){
            temp->next=right;
            right=right->next;
            temp=temp->next;
        }
        while(left!=NULL){
            temp->next=left;
            left=left->next;
            temp=temp->next;
        }
        return bighead->next;
    }
};