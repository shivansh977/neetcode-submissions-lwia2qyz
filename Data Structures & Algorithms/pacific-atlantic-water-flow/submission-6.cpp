class Solution {
private:
    void findAns(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>&vis){
        if(i<0||j<0||i>=heights.size()||j>=heights[0].size()||vis[i][j]){
            return;
        }
        vis[i][j]=true;
        if(i>0&&heights[i-1][j]>=heights[i][j]) findAns(heights,i-1,j,vis);
        if(j>0&&heights[i][j-1]>=heights[i][j]) findAns(heights,i,j-1,vis);
        if(i+1<heights.size()&&heights[i+1][j]>=heights[i][j]) findAns(heights,i+1,j,vis);
        if(j+1<heights[0].size()&&heights[i][j+1]>=heights[i][j]) findAns(heights,i,j+1,vis);
    }   
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> vis1(n,vector<bool>(m,false));
        vector<vector<bool>> vis2(n,vector<bool>(m,false));
        vector<vector<int>> fa;
        for(int i=0;i<n;i++){findAns(heights,i,m-1,vis1);findAns(heights,i,0,vis2);}
        for(int i=0;i<m;i++){findAns(heights,n-1,i,vis1);findAns(heights,0,i,vis2);}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j]&&vis2[i][j])fa.push_back({i,j});
            }
        }
        return fa;
    }
};
