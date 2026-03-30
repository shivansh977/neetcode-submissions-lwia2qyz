class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i==0&&j==0) continue;
                int val1=i>0?grid[i-1][j]:INT_MAX;
                int val2=j>0?grid[i][j-1]:INT_MAX;
                grid[i][j]+=min(val1,val2);
            }
        }
        return grid.back().back();
    }
};