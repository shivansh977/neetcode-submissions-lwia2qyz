class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        if(s1.length()<s2.length()){
            swap(s1,s2);
        }
        if(s2.empty()) return s1==s3;
        int n=s1.length();
        int m=s2.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if((i>0&&s1[i-1]==s3[i+j-1]&&dp[i-1][j])||(j>0&&s2[j-1]==s3[i+j-1]&&dp[i][j-1])){
                    dp[i][j]=true;
                }
            }
        }
        return dp[n][m];
    }
};
