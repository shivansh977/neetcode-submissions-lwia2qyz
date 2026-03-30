class PrefixTree {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isWord = false;
    };
    TrieNode* root;
public:
    PrefixTree() {
        root=new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* curNode=root;
        for(int i=0;i<word.length();i++){
            if(curNode->children[int(word[i]-'a')]==nullptr){
                curNode->children[int(word[i]-'a')]=new TrieNode;
            }
            curNode=curNode->children[int(word[i]-'a')];
        }
        curNode->isWord=true;
    }
    
    bool search(string word) {
        TrieNode* curNode=root;
        for(int i=0;i<word.length();i++){
            if(curNode->children[int(word[i]-'a')]==nullptr){
                return false;
            }
            curNode=curNode->children[int(word[i]-'a')];
        }
        return curNode->isWord;
    }
    
    bool startsWith(string word) {
        TrieNode* curNode=root;
        for(int i=0;i<word.length();i++){
            if(curNode->children[int(word[i]-'a')]==nullptr){
                return false;
            }
            curNode=curNode->children[int(word[i]-'a')];
        }
        return true;
    }
};
