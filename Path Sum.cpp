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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL) return false;
        if(root->left==NULL&&root->right==NULL){
            if(sum==root->val) return true;
            else return false;
        }
        bool a=false,b=false;
        if(root->left!=NULL){
            a=hasPathSum(root->left,sum-root->val);
        }
        if(root->right!=NULL){
            b=hasPathSum(root->right,sum-root->val);
        }
        return a||b;
    }
};