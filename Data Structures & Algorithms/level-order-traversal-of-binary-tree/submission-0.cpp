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
    void lo(TreeNode* root, int level, vector<vector<int>>&fa) {
        if(root==nullptr){
            return;
        }
        if(fa.size()<level+1){
            fa.resize(level+1);
        }
        fa[level].push_back(root->val);
        lo(root->left,level+1,fa);
        lo(root->right,level+1,fa);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> fa;
        lo(root,0,fa);
        return fa;
    }
};
