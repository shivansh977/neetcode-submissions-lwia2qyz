class Solution {
public:
    int numDistinct(string s, string t) {
        int n=t.length();
        int m=s.length();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                int val=0;
                int val1=1;
                if(i>0) val1=dp[i-1][j-1];
                if(j>i) val=dp[i][j-1];
                if(t[i]==s[j]) val+=val1;
                dp[i][j]=val;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
            }cout<<"\n";
        }
        return dp[n-1][m-1];
    }
};
