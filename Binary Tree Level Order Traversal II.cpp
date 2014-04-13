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
    vector<vector<int> > myvec;
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        helper(root, 0);
        for(int i=0;i<myvec.size()/2;i++){
            myvec[i].swap(myvec[myvec.size()-i-1]);
        }
        return myvec;
    }
    void helper(TreeNode *root, int deep){
        if(root==NULL) return ;
        if(myvec.size()<=deep){
            vector<int> subvec;
            subvec.push_back(root->val);
            myvec.push_back(subvec);
        }
        else{
            myvec[deep].push_back(root->val);
        }
        helper(root->left,deep+1);
        helper(root->right,deep+1);
    }
};