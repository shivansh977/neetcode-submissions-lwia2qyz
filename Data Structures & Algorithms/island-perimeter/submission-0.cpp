class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int fa=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int l=1;
                    int r=1;
                    int u=1;
                    int d=1;
                    if(i>0&&grid[i-1][j]) u=0;
                    if(j>0&&grid[i][j-1]) l=0;
                    if(i<n-1&&grid[i+1][j]) r=0;
                    if(j<m-1&&grid[i][j+1]) d=0;
                    fa+=(u+l+r+d);
                }
            }
        }
        return fa;
    }
};