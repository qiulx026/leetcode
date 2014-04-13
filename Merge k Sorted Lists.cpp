/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
struct cmp {
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<ListNode *, vector<ListNode *>, cmp> queue;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                queue.push(lists[i]);
            }
        }
        ListNode *head = NULL, *prev = NULL, *temp;
        while (!queue.empty()) {
            temp = queue.top();
            queue.pop();
            if (prev == NULL) {
                head = temp;
            }
            else {
                prev->next = temp;
            }
            prev = temp;
            
            if (temp->next != NULL) {
                queue.push(temp->next);
            }
        }
        return head;
    }
};