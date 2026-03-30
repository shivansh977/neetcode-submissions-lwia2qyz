class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=1;i<=n;i++){
            if(2*i<=n) dp[2*i]=dp[i];
            if(2*i+1<=n) dp[2*i+1]=1+dp[i];
        }
        return dp;
    }
};
