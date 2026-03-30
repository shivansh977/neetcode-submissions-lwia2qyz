struct TrieNode{
    bool isWord=false;
    TrieNode* children[26];
};
class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root=new TrieNode();
    }
    TrieNode* getRoot(){
        return this->root;
    }
    void addWord(string& s){
        TrieNode* cur=this->root;
        for(int i=0;i<s.length();i++){
            if(cur->children[int(s[i]-'a')]==nullptr){
                cur->children[int(s[i]-'a')]=new TrieNode();
            }
            cur=cur->children[int(s[i]-'a')];
        }
        cur->isWord=true;
    }
};
class Solution {
private:
    Trie trie;
    bool rec(vector<vector<string>>& fa, vector<string>& curS, string& s, int id, TrieNode* cur, string& trieTrace){
        if(id==s.length()){
            if(cur->isWord){
                curS.push_back(trieTrace);
                fa.push_back(curS);
                curS.pop_back();
                return true;
            }
            return false;
        }
        if(cur->children[int(s[id]-'a')]==nullptr){
            return false;
        }
        bool ans=false;
        trieTrace.push_back(s[id]);
        TrieNode* tp=cur;
        cur=cur->children[int(s[id]-'a')];
        ans=ans|rec(fa,curS,s,id+1,cur,trieTrace);
        if(cur->isWord){
            TrieNode* prev=cur;
            cur=trie.getRoot();
            curS.push_back(trieTrace);
            string oldTrieTrace=trieTrace;
            trieTrace="";
            ans=ans|rec(fa,curS,s,id+1,cur,trieTrace);
            cur=prev;
            trieTrace=oldTrieTrace;
            curS.pop_back();
        }
        cur=tp;
        trieTrace.pop_back();
        return ans;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string& word:wordDict) this->trie.addWord(word);
        vector<vector<string>> fa;
        vector<string> curS;
        TrieNode* cur=this->trie.getRoot();
        string trieTrace="";
        if(!rec(fa,curS,s,0,cur,trieTrace)){
            return {};
        }
        vector<string> ffa;
        for(int i=0;i<fa.size();i++){
            string tmp="";
            for(const string& ss:fa[i]) {tmp=tmp+ss;tmp+=" ";}
            tmp.pop_back();
            ffa.push_back(tmp);
        }
        return ffa;
    }
};