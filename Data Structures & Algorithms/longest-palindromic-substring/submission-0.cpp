class Solution {
private:
    string findAns(string& s, int i, int j){
        while(i>0&&j+1<s.length()&&s[i-1]==s[j+1]){
            i--;j++;
        }
        return s.substr(i,j-i+1);
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            string tmp=findAns(s,i,i);
            string tmp1="";
            if(i+1<s.length()&&s[i+1]==s[i]) {tmp1=findAns(s,i,i+1);}
            if(tmp.length()>ans.length()) ans=tmp;
            if(tmp1.length()>ans.length()) ans=tmp1;
        }
        return ans;
    }
};
