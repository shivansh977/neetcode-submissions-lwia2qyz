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
    void rsv(TreeNode* root, int lvl, vector<int>&fa){
        if(root==nullptr) return;
        if(lvl>=fa.size()) fa.resize(lvl+1);
        fa[lvl]=root->val;
        rsv(root->left,lvl+1,fa);
        rsv(root->right,lvl+1,fa);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> fa;
        rsv(root,0,fa);
        return fa;
    }
};
