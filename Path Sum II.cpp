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
    vector<vector<int> > solution;
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if(root==NULL) return solution;
        vector<int> temp;
        path(root,sum,temp);
        return solution;
    }
    void path(TreeNode *root, int sum, vector<int> temp){
        temp.push_back(root->val);
        if(root->right==NULL&&root->left==NULL){
            if(root->val==sum) {
                solution.push_back(temp);
                return ;
            }
        }
        if(root->right!=NULL){
            path(root->right,sum-root->val,temp);
        }
        if(root->left!=NULL){
            path(root->left,sum-root->val,temp);
        }
    }
};