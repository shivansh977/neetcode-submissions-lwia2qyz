class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int totsum=0;
        for(int s:stones) totsum+=s;
        vector<vector<int>> dp(n,vector<int>(totsum+1,0));
        for(int i=2*stones[0];i<=totsum;i++) dp[0][i]=stones[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=totsum;j++){
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                if(j-(2*stones[i])>=0) dp[i][j]=max(dp[i][j],stones[i]+dp[i-1][j-(2*stones[i])]);
            }
        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                cout<<dp[i][j]<<" ";
            }cout<<"\n";
        }
        return totsum-2*dp.back().back();
    }
};