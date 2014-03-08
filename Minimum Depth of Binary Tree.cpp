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
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        if(root->left==NULL&&root->right==NULL) return 1;
        if(root->left==NULL&&root->right!=NULL) return minDepth(root->right)+1;
        if(root->left!=NULL&&root->right==NULL) return minDepth(root->left)+1;
        if(root->left!=NULL&&root->right!=NULL){
            int le=minDepth(root->left);
            int ri=minDepth(root->right);
            if(le>ri) le=ri;
            return le+1;
        }
        
    }
};