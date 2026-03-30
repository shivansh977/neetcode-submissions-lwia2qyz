class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        vector<int> dp(n+1,0);
        dp[2]=1;
        for(int i=3;i<=n;i++){
            for(int k=1;k<i;k++){
                dp[i]=max(dp[i], max(dp[i-k],i-k)*k);
            }
        }
        return dp[n];
    }
};



//n -> solve(n-k)*k;