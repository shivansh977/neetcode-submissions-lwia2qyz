class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=grid[0][0];
        priority_queue<vector<int>> pq;
        pq.push({-dist[0][0],0,0});
        while(!pq.empty()){
            vector<int> x=pq.top();
            pq.pop();
            int val=-x[0];
            int i=x[1];
            int j=x[2];
            if(dist[i][j]<val) continue;
            if(i>0&&dist[i-1][j]>max(grid[i-1][j],val)) {dist[i-1][j]=max(grid[i-1][j],val);pq.push({-max(grid[i-1][j],val),i-1,j});}
            if(j>0&&dist[i][j-1]>max(grid[i][j-1],val)) {dist[i][j-1]=max(grid[i][j-1],val);pq.push({-max(grid[i][j-1],val),i,j-1});}
            if(i<grid.size()-1&&dist[i+1][j]>max(grid[i+1][j],val)) {dist[i+1][j]=max(grid[i+1][j],val);pq.push({-max(grid[i+1][j],val),i+1,j});}
            if(j<grid[0].size()-1&&dist[i][j+1]>max(grid[i][j+1],val)) {dist[i][j+1]=max(grid[i][j+1],val);pq.push({-max(grid[i][j+1],val),i,j+1});}
        }
        return dist.back().back();
    }
};
