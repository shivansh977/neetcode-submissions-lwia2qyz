struct TrieNode{
    bool isWord=false;
    TrieNode* children[26] = {nullptr};
};

class Trie {
private:
    TrieNode* root;
    void insertWord(string s, TrieNode* curNode, int id){
        if(id==s.length()) {
            curNode->isWord=true;
            return;
        }
        if(curNode->children[int(s[id]-'a')]==nullptr){
            curNode->children[int(s[id]-'a')]=new TrieNode();
        }
        TrieNode* nextNode=curNode->children[int(s[id]-'a')];
        insertWord(s,nextNode,id+1);
    }
public:
    Trie(){
        root=new TrieNode();
    }
    TrieNode* getRoot(){
        return root;
    }
    void addWord(string s){
        insertWord(s,root,0);
    }
};

class Solution {
private:
    TrieNode* nextNode(TrieNode* curNode, char c){
        return curNode->children[int(c-'a')];
    }    
    bool isWord(TrieNode* curNode){
        if(curNode!=nullptr&&curNode->isWord) return true;
        return false;
    }
    void findWord(vector<vector<char>>& board, vector<vector<bool>>& vis,int i, int j, string s, TrieNode* curNode, set<string>& fa){
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||vis[i][j]) return;
        TrieNode* next=nextNode(curNode,board[i][j]);
        if(next==nullptr) return;
        vis[i][j]=true;
        s.push_back(board[i][j]);
        if(isWord(next)) fa.insert(s);
        findWord(board,vis,i-1,j,s,next,fa);
        findWord(board,vis,i,j-1,s,next,fa);
        findWord(board,vis,i+1,j,s,next,fa);
        findWord(board,vis,i,j+1,s,next,fa);
        vis[i][j]=false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        set<string> fa;
        vector<string> fa1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<words.size();i++){
            trie.addWord(words[i]);
        }
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                findWord(board,vis,i,j,"",trie.getRoot(),fa);
            }
        }
        for(string s:fa){
            fa1.push_back(s);
        }
        return fa1;
    }
};
