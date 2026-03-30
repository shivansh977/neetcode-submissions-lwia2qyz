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
    void ksmall(TreeNode* root, int& nodes_seen, int& ans, int target){
        if(root==nullptr) return;
        ksmall(root->left,nodes_seen,ans,target);
        nodes_seen++;
        if(nodes_seen<=target) ans=root->val;
        ksmall(root->right,nodes_seen,ans,target);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        int nodes_seen=0;
        ksmall(root,nodes_seen,ans,k);
        return ans;
    }
};
