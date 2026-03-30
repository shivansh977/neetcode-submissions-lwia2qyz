struct TrieNode{
    bool isWord;
    TrieNode* children[26];
    TrieNode() {
        isWord = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root=new TrieNode;
    }
    TrieNode* getRoot(){
        return root;
    }
    void addWord(string& s){
        TrieNode* cur=root;
        for(int i=0;i<s.length();i++){
            if(cur->children[int(s[i]-'a')]==nullptr){
                cur->children[int(s[i]-'a')]=new TrieNode;
            }
            cur=cur->children[int(s[i]-'a')];
        }
        cur->isWord=true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie trie;
        int n=s.length();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
        for(int i=0;i<dictionary.size();i++){
            trie.addWord(dictionary[i]);
        }
        for(int st=0;st<s.length();st++){
            TrieNode* cur=trie.getRoot();
            for(int en=st;en<s.length();en++){
                if(cur->children[int(s[en]-'a')]==nullptr){
                    break;
                }
                cur=cur->children[int(s[en]-'a')];
                if(cur->isWord){
                    dp[st][en]=true;
                }
            }
        }
        vector<int> fdp(n+1,0);
        for(int i=0;i<=n;i++) fdp[i]=i;
        for(int i=0;i<n;i++){
            fdp[i+1]=min(fdp[i]+1,fdp[i+1]);
            for(int j=0;j<=i;j++){
                if(dp[j][i]) fdp[i+1]=min(fdp[i+1],fdp[j]);
            }
        }
        return fdp[n];
    }
};