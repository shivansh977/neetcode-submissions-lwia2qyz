class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<bool> vis(n*m,false);
        vector<vector<int>> adj(n*m);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]<0) continue;
                int node=m*i+j;
                int node1=m*(i+1)+j;
                int node2=m*i+1+j;
                if(grid[i][j]==0) q.push({m*i+j,0});
                if(i+1<n&&grid[i+1][j]>=0){
                    adj[node].push_back(node1);
                    adj[node1].push_back(node);
                }
                if(j+1<m&&grid[i][j+1]>=0){
                    adj[node].push_back(node2);
                    adj[node2].push_back(node);
                }
            }
        }
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(grid[node.first/m][node.first%m]<0) continue;
            vis[node.first]=true;
            for(int i=0;i<adj[node.first].size();i++){
                if(!vis[adj[node.first][i]]) q.push({adj[node.first][i],node.second+1});
            }
            grid[node.first/m][node.first%m]=min(grid[node.first/m][node.first%m],node.second);
        }
    }
};
//BFS Problem
