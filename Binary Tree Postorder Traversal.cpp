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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> a;
        map<TreeNode* , int> mmap;
        stack<TreeNode*> st;
        if (root==NULL) return a;
        st.push(root);
        TreeNode* p;
        while(!st.empty()){
            p=st.top();
            if((p->right==NULL&&p->left==NULL)||(mmap.find(p)!=mmap.end())){
                a.push_back(p->val);
                st.pop();
            }
            else{
                if(p->right!=NULL) st.push(p->right);
                if(p->left!=NULL) st.push(p->left);
                mmap[p]=1;
            }
        }
        return a;
    }
};