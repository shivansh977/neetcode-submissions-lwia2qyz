class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>>& dp=obstacleGrid;
        int n=dp.size();
        int m=dp[0].size();
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) continue;
                int val1=i>0?dp[i-1][j]:0;
                int val2=j>0?dp[i][j-1]:0;
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else dp[i][j]=val1+val2;
            }
        }
        return dp[n-1][m-1];
    }
};