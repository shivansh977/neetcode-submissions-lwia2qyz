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
//Encode it as, preorder and then inorder separated by commas!
class Codec {
private:
    void solve1(vector<string>& fa, vector<TreeNode*>& v){
        while(true){
            vector<TreeNode*> tmp;
            for(TreeNode* x:v){
                if(x!=nullptr){
                    tmp.push_back(x->left);
                    tmp.push_back(x->right);
                    fa.push_back(to_string(x->val));
                }
                else{
                    fa.push_back("n");
                }
            }
            if(tmp.empty()) break;
            v=tmp;
        }
    }
    TreeNode* solve2(vector<string>& chunks, int id, vector<TreeNode*>& v){
        TreeNode* root=v[0];
        while(!v.empty()){
            vector<TreeNode*> tmp;
            for(TreeNode* x:v){
                if(x!=nullptr){
                    x->left=chunks[id]=="n"?nullptr:new TreeNode(stoi(chunks[id]));id++;
                    x->right=chunks[id]=="n"?nullptr:new TreeNode(stoi(chunks[id]));id++;
                    tmp.push_back(x->left);
                    tmp.push_back(x->right);
                }
            }
            v=tmp;
        }
        return root;
    }
public:
    string serialize(TreeNode* root) {
        vector<string> fa;
        vector<TreeNode*> vec={root};
        solve1(fa,vec);
        string ffa="";
        for(const string& x:fa){
            ffa+=x;
            ffa.push_back(',');
        }ffa.pop_back();
        return ffa;
    }

    TreeNode* deserialize(string data) {
        if(data=="n") return nullptr;
        vector<string> chunks;
        string tmp="";
        for(char ch:data){
            if(ch==','){
                chunks.push_back(tmp);
                tmp="";
            }
            else{
                tmp.push_back(ch);
            }
        }
        chunks.push_back(tmp);
        vector<TreeNode*> v;
        v.push_back(new TreeNode(stoi(chunks[0])));
        return solve2(chunks,1,v);
    }
};
