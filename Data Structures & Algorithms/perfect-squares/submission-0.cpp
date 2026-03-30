class Solution {
public:
    int numSquares(int n) {
        vector<int> ps;
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i*i<=n;i++){
            ps.push_back(i*i);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<ps.size();j++){
                if(i-ps[j]>=0) dp[i]=min(dp[i-ps[j]]+1,dp[i]);
            }
        }
        return dp[n];
    }
};