class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis){
        if(vis[node]) return;
        vis[node]=true;
        for(int i=0;i<adj[node].size();i++){
            dfs(adj[node][i],adj,vis);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> adj(n*m);
        vector<bool> vis(n*m,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!='1') continue;
                if(i+1<n&&grid[i+1][j]=='1'){
                    int n1=m*i+j;
                    int n2=m*(i+1)+j;
                    adj[n1].push_back(n2);
                    adj[n2].push_back(n1);
                }
                if(j+1<m&&grid[i][j+1]=='1'){
                    int n1=m*i+j;
                    int n2=m*i+j+1;
                    adj[n1].push_back(n2);
                    adj[n2].push_back(n1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!vis[m*i+j]){
                    ans++;dfs(m*i+j,adj,vis);
                    cout<<i<<" "<<j<<"\n";
                }
            }
        }
        return ans;
    }
};
