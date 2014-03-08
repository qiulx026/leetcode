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
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        TreeNode *p=root;
        vector<int> a;
        while (p!=NULL||!s.empty()){
            while(p!=NULL){
                s.push(p);
                p=p->left;
            }
            if(!s.empty()){
                p=s.top();
                a.push_back(p->val);
                s.pop();
                p=p->right;
            }
        }
        return a;
    }
};