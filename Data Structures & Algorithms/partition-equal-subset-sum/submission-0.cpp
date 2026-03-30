class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totsum=0;
        for(int i=0;i<n;i++) totsum+=nums[i];
        if(totsum%2) return false;
        vector<vector<bool>> dp(n,vector<bool>(5000));
        dp[0][nums[0]]=true;
        dp[0][0]=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<5000;j++){
                dp[i][j]=dp[i-1][j]|dp[i][j];
                if(j+nums[i]<5000){
                    dp[i][j+nums[i]]=dp[i-1][j]|dp[i][j+nums[i]];
                }
            }
        }
        return dp[n-1][totsum/2];
    }
};
