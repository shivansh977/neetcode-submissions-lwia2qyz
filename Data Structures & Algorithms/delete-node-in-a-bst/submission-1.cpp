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
    TreeNode* find(TreeNode* node, int key, TreeNode*& parent, TreeNode* par){
        if(node->left==nullptr&&node->right==nullptr){
            TreeNode* fa=node->val==key?node:nullptr;
            if(fa!=nullptr) parent=par;
            return fa;
        }
        if(node->val==key){
            parent=par;
            return node;
        }
        TreeNode* n;
        if(key<node->val) n=find(node->left,key,parent,node);
        else n=find(node->right,key,parent,node);
        return n;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        TreeNode* parent=nullptr;
        TreeNode* delNode=find(root,key,parent,nullptr);
        TreeNode* nNode=nullptr;
        if(delNode==nullptr) return root;
        if(delNode->left==nullptr&&delNode->right!=nullptr){
            nNode=delNode->right;
        }
        else if(delNode->left!=nullptr&&delNode->right==nullptr){
            nNode=delNode->left;
        }
        else if(delNode->left!=nullptr&&delNode->right!=nullptr){
            nNode=delNode->right;
            TreeNode* l=delNode->left;
            TreeNode* el=nNode;
            while(el->left!=nullptr){
                el=el->left;
            }
            el->left=l;
        }
        delNode->left=nullptr;
        delNode->right=nullptr;
        delete delNode;
        if(parent==nullptr){
            return nNode;
        }
        bool isLeftFromPar=parent->val>key;
        if(isLeftFromPar) parent->left=nNode;
        else parent->right=nNode;    
        return root;
    }
};