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
    vector<int> preorderTraversal(TreeNode *root) {
        TreeNode *p=root;
        stack<TreeNode*> s;
        vector<int> a;
        while(p!=NULL||!s.empty()){
            while(p!=NULL){
                a.push_back(p->val);
                s.push(p->right);
                p=p->left;
            }
            if(!s.empty()){
                p=s.top();
                s.pop();
            }
        }
        return a;
        
    }
};