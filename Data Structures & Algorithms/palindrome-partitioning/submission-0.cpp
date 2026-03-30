class Solution {
private:
    bool isPallin(string &s, int st, int en){
        while(st<en){
            if(s[st]!=s[en]) return false;
            st++;en--;
        }
        return true;
    }
    void find(vector<vector<string>>& fa, vector<string>& cur,string& s, int st){
        if(st==s.length()){
            fa.push_back(cur);
            return;
        }
        for(int i=st;i<s.length();i++){
            if(isPallin(s,st,i)){
                cur.push_back(s.substr(st,i-st+1));
                find(fa,cur,s,i+1);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> fa;
        vector<string> cur;
        find(fa,cur,s,0);
        return fa;
    }
};
