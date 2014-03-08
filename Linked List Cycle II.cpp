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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode *, int> m;
        ListNode *p=head;
        while(p!=NULL){
            if(m.find(p)==m.end()) {m[p]=1;p=p->next;}
            else return p;
        }
        return NULL;
    }
};