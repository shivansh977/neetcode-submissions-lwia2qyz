class Solution {
public:
    bool isMatch(string s, string p) {
        int n=p.length();
        int m=s.length();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(p[i-1]>='a'&&p[i-1]<='z'){
                    bool val=dp[i-1][j-1];
                    if(j>0&&p[i-1]==s[j-1]){
                        dp[i][j]=dp[i][j]|val;
                    }
                }
                else if(p[i-1]=='.'){
                    bool val=dp[i-1][j-1];
                    if(j>0) dp[i][j]=dp[i][j]|val;
                }
                else if(p[i-1]=='*'){
                    if(i>1) dp[i][j]=dp[i][j]|dp[i-2][j];
                    if(i>1&&j>0&&(p[i-2]=='.'||p[i-2]==s[j-1])){
                        dp[i][j]=dp[i][j]|dp[i][j-1];
                    }
                }
            }
        }
        for(int i=0;i<=n;i++){
            if(i>0) cout<<p[i-1]<<" ";
            for(int j=0;j<=m;j++){
                cout<<dp[i][j]<<" ";
            }cout<<"\n";
        }
        return dp[n][m];
    }
};
