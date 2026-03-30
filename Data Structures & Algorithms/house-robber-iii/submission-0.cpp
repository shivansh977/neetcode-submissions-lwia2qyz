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
    int solve(TreeNode* root, bool inc){
        if(root==nullptr) return 0;
        if(inc){
            return root->val+solve(root->left,!inc)+solve(root->right,!inc);
        }
        return max(solve(root->left,true),solve(root->left,false))+max(solve(root->right,true),solve(root->right,false));
    }
public:
    int rob(TreeNode* root) {
        return max(solve(root,false),solve(root,true));
    }
};