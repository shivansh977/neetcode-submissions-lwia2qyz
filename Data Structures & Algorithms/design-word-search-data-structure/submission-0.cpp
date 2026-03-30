struct TreeNode{
    bool isWord=false;
    TreeNode* children[26] = {nullptr};
};

class WordDictionary {
private:
    TreeNode* root;
    bool serch(TreeNode* cur, int id, string& word){
        if(cur==nullptr) return false;
        if(id==word.length()) return cur->isWord;
        bool ans=false;
        if(word[id]=='.'){
            for(int i=0;i<26;i++){
                ans=ans|serch(cur->children[i],id+1,word);
            }
        }
        else{
            ans=ans|serch(cur->children[int(word[id]-'a')],id+1,word);
        }
        return ans;
    }
public:
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* cur=root;
        for(int i=0;i<word.length();i++){
            if(cur->children[int(word[i]-'a')]==nullptr){
                cur->children[int(word[i]-'a')]=new TreeNode();
            }
            cur=cur->children[int(word[i]-'a')];
        }
        cur->isWord=true;
    }

    bool search(string word) {
        return serch(root,0,word);
    }
};
