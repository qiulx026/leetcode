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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > myvec;
        vector<TreeNode*>  tovisit;
        bool flag=false;
        if(root==NULL)  return myvec;
        tovisit.push_back(root);
        while(!tovisit.empty()){
            vector<int> temp;
            vector< TreeNode*> temp1;
            for(int i=0;i<tovisit.size();i++){
                temp.push_back(tovisit[i]->val);
            }
            myvec.push_back(temp);
            for(int i=tovisit.size()-1;i>=0;i--){
                if(flag==true){
                    if(tovisit[i]->left!=NULL) temp1.push_back(tovisit[i]->left);
                    if(tovisit[i]->right!=NULL) temp1.push_back(tovisit[i]->right);
                }
                else{
                    if(tovisit[i]->right!=NULL) temp1.push_back(tovisit[i]->right);
                    if(tovisit[i]->left!=NULL) temp1.push_back(tovisit[i]->left);
                }
            }
            tovisit.swap(temp1);
            if(flag==true)  flag=false;
            else flag=true;
            
        }
        return myvec;
    }
};