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
    pair<bool,int> balanced(TreeNode* root){
        if(root==nullptr){
            return {true,0};
        }
        auto val1=balanced(root->left);
        auto val2=balanced(root->right);
        bool isValid=(max(val1.second,val2.second)-min(val1.second,val2.second)<=1)&&val1.first&&val2.first;
        int maxD=max(val1.second,val2.second)+1;
        return {isValid,maxD};
    }
public:
    bool isBalanced(TreeNode* root) {
        auto v=balanced(root);
        return v.first;
    }
};
