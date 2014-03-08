/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *insertNode(vector<int> &num, int l, int h){
        if (l>h) return NULL;
        if(l==h) return new TreeNode(num[l]);
        int m=(l+h)/2;
        TreeNode *p=new TreeNode(num[m]);
        p->left=insertNode(num,l,m-1);
        p->right=insertNode(num,m+1,h);
        return p;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> num;
        while(head!=NULL){num.push_back(head->val);head=head->next;}
        return insertNode(num,0,num.size()-1);
        
    }
};