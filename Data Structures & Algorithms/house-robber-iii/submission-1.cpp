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
    int solve(TreeNode* root, bool inc, map<pair<TreeNode*,bool>,int>& dp){
        if(root==nullptr) return 0;
        if(dp.count({root,inc})) return dp[{root,inc}];
        int ans=0;
        if(inc){
            ans=root->val+solve(root->left,!inc,dp)+solve(root->right,!inc,dp);
        }
        else ans=max(solve(root->left,true,dp),solve(root->left,false,dp))+max(solve(root->right,true,dp),solve(root->right,false,dp));
        return dp[{root,inc}]=ans;
    }
public:
    int rob(TreeNode* root) {
        map<pair<TreeNode*,bool>,int> dp;
        return max(solve(root,false,dp),solve(root,true,dp));
    }
};