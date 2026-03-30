class Solution {
private:
    void solve(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix){
        int maxans=0;
        if(dp[i][j]>=0) return;
        if(i>0&&matrix[i-1][j]>matrix[i][j]) {solve(i-1,j,dp,matrix);maxans=max(maxans,dp[i-1][j]);}
        if(j>0&&matrix[i][j-1]>matrix[i][j]) {solve(i,j-1,dp,matrix);maxans=max(maxans,dp[i][j-1]);}
        if(i<matrix.size()-1&&matrix[i+1][j]>matrix[i][j]) {solve(i+1,j,dp,matrix);maxans=max(maxans,dp[i+1][j]);}
        if(j<matrix[0].size()-1&&matrix[i][j+1]>matrix[i][j]) {solve(i,j+1,dp,matrix);maxans=max(maxans,dp[i][j+1]);}
        dp[i][j]=maxans+1;
        return;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp=vector<vector<int>>(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(i,j,dp,matrix);
            }
        }
        int fa=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) fa=max(fa,dp[i][j]);
        }
        return fa;
    }
};
