class Solution {
public:
    bool isPalindrome(string s) {
        string x;
        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z'){
                x.push_back('a'+int(s[i]-'A'));
            }
            else if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')) x.push_back(s[i]);
        }
        int n=x.length();
        for(int i=0;i<x.length();i++){
            if(x[i]!=x[n-1-i]) return false;
        }
        return true;
    }
};
