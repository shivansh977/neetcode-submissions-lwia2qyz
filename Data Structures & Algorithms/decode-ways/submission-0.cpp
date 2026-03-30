class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n,0);
        if(s[0]!='0') dp[0]++;
        if(s.length()==1) return dp[0];
        if(s[0]>='1'&&s[0]<='2'&&stoi(s.substr(0,2))<=26) dp[1]++;
        if(s[1]!='0') dp[1]+=dp[0];
        for(int i=2;i<s.length();i++){
            if(s[i]!='0') dp[i]+=dp[i-1];
            if(s[i-1]>='1'&&s[i-1]<='2'&&stoi(s.substr(i-1,2))<=26) dp[i]+=dp[i-2];
        }
        return dp.back();
    }
};
