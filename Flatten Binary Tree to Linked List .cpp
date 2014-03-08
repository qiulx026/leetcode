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
    queue<TreeNode* > s;
    void T(TreeNode *r){
        s.push(r);
        if(r->left!=NULL) T(r->left);
        if(r->right!=NULL) T(r->right);
    }
    void flatten(TreeNode *root) {
        if(root!=NULL){ 
        T(root);
        TreeNode* p=root;;
        s.pop();
        while(!s.empty()){
            p->left=NULL;
            p->right=s.front();
            p=p->right;
            s.pop();
        }
        }
    }
};