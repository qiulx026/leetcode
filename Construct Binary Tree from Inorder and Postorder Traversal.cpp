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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size()==0) return NULL;
        if(inorder.size()==1) {
            TreeNode *root=new TreeNode(inorder.at(0));
            return root;
            }
        int length=inorder.size();
        int root_value=postorder.at(length-1);
        TreeNode *root=new TreeNode(root_value);
        vector<int>::iterator init=inorder.begin(),postit=postorder.begin();
        while((*init)!=root_value){
            init++;
            postit++;
        }
        vector<int> leftinorder(inorder.begin(),init);
        vector<int> rightinorder(init+1,inorder.end());
        vector<int> leftpostorder(postorder.begin(),postit);
        vector<int> rightpostorder(postit,postorder.end()-1);     
        root->left=buildTree(leftinorder,leftpostorder);
        root->right=buildTree(rightinorder,rightpostorder);
        return root;
    }
};