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
//vector structure maxsum, pathsum with node, lsum, rsum
class Solution {
private:
    vector<int> solver(TreeNode* root){
        vector<int> ans(4,0);
        if(root->left==nullptr&&root->right==nullptr){
            return {root->val,root->val,root->val,root->val};
        }
        vector<int> lsol = {INT_MIN,0,0,0};
        vector<int> rsol = {INT_MIN,0,0,0};
        if(root->left!=nullptr) lsol = solver(root->left);
        if(root->right!=nullptr) rsol = solver(root->right);
        ans[2]=max(lsol[2],lsol[3])+root->val;
        ans[3]=max(rsol[2],rsol[3])+root->val;
        ans[2]=max(ans[2],root->val);
        ans[3]=max(ans[3],root->val);
        ans[1]=max(lsol[2],lsol[3])+max(rsol[2],rsol[3])+root->val;
        ans[1]=max(ans[1],max(ans[2],ans[3]));
        ans[0]=max(ans[1],max(lsol[0],rsol[0]));
        return ans;
    }
public:
    int maxPathSum(TreeNode* root) {
        vector<int> ans = solver(root);
        return ans[0];
    }
};
