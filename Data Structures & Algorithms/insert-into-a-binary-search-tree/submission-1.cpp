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
    void insert(TreeNode* root, int val){
        if(root->left==nullptr&&val<root->val){
            root->left=new TreeNode(val);
            return;
        }
        else if(root->right==nullptr&&val>root->val){
            root->right=new TreeNode(val);
            return;
        }
        if(root->left!=nullptr&&val<root->val) insert(root->left,val);
        else if(root->right!=nullptr&&val>root->val) insert(root->right,val);
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            root=new TreeNode(val);
        }
        insert(root,val);
        return root;
    }
};