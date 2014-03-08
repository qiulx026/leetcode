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
private:
    vector<vector<int> > ret;
public:
    void solve(int dep, TreeNode *root)
    {
        if (root == NULL)
            return;
            
        if (ret.size() > dep)
        {
            ret[dep].push_back(root->val);
        }
        else
        {
            vector<int> a;
            a.push_back(root->val);
            ret.push_back(a);
        }
        
        solve(dep + 1, root->left);
        solve(dep + 1, root->right);
    }
    
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        solve(0, root);
        
        return ret;
    }
};