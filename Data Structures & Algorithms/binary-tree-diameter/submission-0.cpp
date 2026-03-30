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
    vector<int> diameter(TreeNode* root){
        if(root==nullptr){
            return {0,0,0};
        }
        vector<int> l=diameter(root->left);
        vector<int> r=diameter(root->right);
        vector<int> ans(3);
        ans[2]=max(r[2],r[1])+1;
        ans[1]=max(l[2],l[1])+1;
        ans[0]=(ans[2]+ans[1]-1);
        ans[0]=max(ans[0],max(l[0],r[0]));
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        ans=diameter(root);
        return ans[0]-1;
    }
};
