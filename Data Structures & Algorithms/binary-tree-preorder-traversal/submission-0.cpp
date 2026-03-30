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
    void rec(vector<int>& fa, TreeNode* root){
        if(root==nullptr){
            return;
        }
        fa.push_back(root->val);
        rec(fa,root->left);
        rec(fa,root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> fa;
        rec(fa,root);
        return fa;
    }
};