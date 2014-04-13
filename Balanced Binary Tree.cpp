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
    bool isBalanced(TreeNode *root) {
        int i=balance(root);
        if(i>=0) return true;
        else return false;
    }
    int balance(TreeNode *root){
        if(root==NULL) return 0;
        int left=balance(root->left);
        int right=balance(root->right);
        if(left==-1||right==-1) return -1;
        if(left-right>1||right-left>1) return -1;
        return max(left,right)+1;
    }
};