class NumMatrix {
private:
    vector<vector<int>> dp;
    int n;
    int m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp=matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j>0) dp[i][j]+=dp[i][j-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>0) dp[j][i]+=dp[j-1][i];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int tot=dp[row2][col2];
        int v1=row1>0?dp[row1-1][col2]:0;
        int v2=col1>0?dp[row2][col1-1]:0;
        int v3=row1>0&&col1>0?dp[row1-1][col1-1]:0;
        return tot-v1-v2+v3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */