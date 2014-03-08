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
    int s(TreeNode *root, int n){
        int x=0;
        n=10*n+root->val;
        if(root->left!=NULL) {x+=s(root->left,n);}
        if(root->right!=NULL) {x+=s(root->right,n);}
        if(root->left==NULL&&root->right==NULL) {return n;}
        return x;
    }
    int sumNumbers(TreeNode *root) {
        if(root==NULL) return 0;
        int x=s(root,0);
        return x;
        
    }
};