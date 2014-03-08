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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        else return iss(root->left,root->right);
    }
    bool iss(TreeNode *p, TreeNode *q){
        if(p==NULL&&q==NULL) return true;
        if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL)) return false;
        if(p!=NULL&&q!=NULL){
            if(q->val!=p->val) return false;
            if(iss(q->right,p->left)&&iss(q->left,p->right)) return true;
            else return false;
        }
    }
};