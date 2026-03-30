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
    pair<bool,pair<int,int>> isValid(TreeNode* root){
        if(root==nullptr) return {true,{INT_MIN,INT_MAX}};
        pair<bool,pair<int,int>> ans={true,{INT_MIN,INT_MAX}};
        pair<bool,pair<int,int>> lsol=isValid(root->left);
        pair<bool,pair<int,int>> rsol=isValid(root->right);
        ans.first=ans.first&lsol.first;
        ans.first=ans.first&rsol.first;
        ans.first=ans.first&(root->val>lsol.second.first);
        ans.first=ans.first&(root->val<rsol.second.second);
        ans.second.first=max(max(root->val,ans.second.first),max(lsol.second.first,rsol.second.first));
        ans.second.second=min(min(root->val,ans.second.second),min(lsol.second.second,rsol.second.second));
        return ans;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root).first;
    }
};
