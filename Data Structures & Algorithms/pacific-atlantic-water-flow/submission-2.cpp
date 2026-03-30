class Solution {
private:
    bool findAns(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>&vis, vector<vector<bool>>&vis1, int x, int y){
        if(i<0||j<0||i>=heights.size()||j>=heights[0].size()||(vis[i][j]&&!vis1[i][j])){
            return false;
        }
        if(vis[i][j]){
            return vis1[i][j];
        }
        vis[i][j]=true;
        bool ans=(i==x)||(j==y);
        if(ans==true) vis1[i][j]=true;
        if(i>0&&heights[i-1][j]<=heights[i][j]) ans=ans|findAns(heights,i-1,j,vis,vis1,x,y);
        if(j>0&&heights[i][j-1]<=heights[i][j]) ans=ans|findAns(heights,i,j-1,vis,vis1,x,y);
        if(i+1<heights.size()&&heights[i+1][j]<=heights[i][j]) ans=ans|findAns(heights,i+1,j,vis,vis1,x,y);
        if(j+1<heights[0].size()&&heights[i][j+1]<=heights[i][j]) ans=ans|findAns(heights,i,j+1,vis,vis1,x,y);
        vis1[i][j]=ans;
        vis[i][j]=false;
        return vis1[i][j];
    }   
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<bool>> vis1(n,vector<bool>(m,false));
        vector<vector<bool>> vis2(n,vector<bool>(m,false));
        vector<vector<int>> fa;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                findAns(heights,i,j,vis,vis1,0,0);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                findAns(heights,i,j,vis,vis2,n-1,m-1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j]&&vis2[i][j])fa.push_back({i,j});
            }
        }
        return fa;
    }
};
