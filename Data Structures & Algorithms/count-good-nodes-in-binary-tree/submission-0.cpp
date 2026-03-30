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
    void calcGN(TreeNode* root, int& fa, int maxNode) {
        if(root==nullptr) return;
        if(root->val>=maxNode) fa++;
        maxNode=max(maxNode,root->val);
        calcGN(root->left,fa,maxNode);
        calcGN(root->right,fa,maxNode);
    }
public:
    int goodNodes(TreeNode* root) {
        int fa=0;
        calcGN(root,fa,INT_MIN);
        return fa;
    }
};
