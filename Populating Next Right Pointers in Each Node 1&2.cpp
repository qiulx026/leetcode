/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
private: vector<vector<TreeLinkNode *> >  ret;
public:
    void connect(TreeLinkNode *root) {
        ret.clear();
        solve(0, root);
        int length=ret.size();
        int i,j,sublength;
        for(i=0;i<length;i++){
            sublength=ret[i].size();
            for(j=0;j<sublength-1;j++){
                ret[i][j]->next=ret[i][j+1];
            }
        }
        
    }
        void solve(int dep, TreeLinkNode *root)
    {
        if (root == NULL)
            return;
            
        if (ret.size() > dep)
        {
            ret[dep].push_back(root);
        }
        else
        {
            vector<TreeLinkNode *> a;
            a.push_back(root);
            ret.push_back(a);
        }
        
        solve(dep + 1, root->left);
        solve(dep + 1, root->right);
    }
};