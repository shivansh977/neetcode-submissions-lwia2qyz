/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    TreeNode* bTree(vector<int>& preorder, vector<int>& inorder, int& id, int st, int en){
        if(id==preorder.size()||st==-1){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[id++]);
        int x=-1;
        for(int i=st;i<=en;i++){
            if(inorder[i]==root->val) x=i;
        }
        if(x>st) root->left=bTree(preorder,inorder,id,st,x-1);
        if(x<en) root->right=bTree(preorder,inorder,id,x+1,en);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int id=0;
        int n=preorder.size();
        return bTree(preorder,inorder,id,0,n-1);
    }
};
