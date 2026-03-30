class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<map<int,int>> dp(n);
        dp[0][nums[0]]++;
        dp[0][-nums[0]]++;
        for(int i=1;i<n;i++){
            for(auto it=dp[i-1].begin();it!=dp[i-1].end();it++){
                dp[i][it->first+nums[i]]+=it->second;
                dp[i][it->first-nums[i]]+=it->second;
            }
        }
        return dp[n-1][target];
    }
};
// 4 6 8
