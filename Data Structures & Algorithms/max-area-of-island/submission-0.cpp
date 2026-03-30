class Solution {
private:
    int dfs(int node, vector<vector<int>>&adj, vector<bool>&vis){
        if(vis[node]) return 0;
        vis[node]=true;
        int ans=1;
        for(int i=0;i<adj[node].size();i++){
            ans+=dfs(adj[node][i],adj,vis);
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<bool> vis(n*m,false);
        vector<vector<int>> adj(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=1) continue;
                int node=i*m+j;
                int node1=(i+1)*m+j;
                int node2=i*m+1+j;
                if(i+1<n&&grid[i+1][j]==1){
                    adj[node].push_back(node1);
                    adj[node1].push_back(node);
                }
                if(j+1<m&&grid[i][j+1]==1){
                    adj[node].push_back(node2);
                    adj[node2].push_back(node);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&!vis[m*i+j]){
                    ans=max(ans,dfs(m*i+j,adj,vis));
                }
            }
        }
        return ans;
    }
};
