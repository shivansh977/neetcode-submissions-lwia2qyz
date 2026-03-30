class Solution {
private:
    vector<int> bfs(vector<vector<int>>&adj, vector<int>& ini){
        int n=adj.size();
        queue<int> q;
        vector<int> dist(n,-1);
        vector<bool> vis(n,false);
        for(int i=0;i<ini.size();i++){
            q.push(ini[i]);
            dist[ini[i]]=0;
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            vis[node]=true;
            for(int neighbour: adj[node]){
                if(!vis[neighbour]){
                    q.push(neighbour);
                    if(dist[neighbour]!=-1) dist[neighbour]=min(dist[node]+1,dist[neighbour]);
                    else dist[neighbour]=dist[node]+1;
                }
            }
        }
        return dist;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=int(grid.size())*int(grid[0].size());
        int m=grid[0].size();
        vector<vector<int>> adj(n);
        vector<int> ini;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>=1){
                    if(i+1<grid.size()&&grid[i+1][j]>=1){
                        adj[i*m+j].push_back((i+1)*m+j);
                        adj[(i+1)*m+j].push_back(i*m+j);
                    }
                    if(j+1<m&&grid[i][j+1]>=1){
                        adj[i*m+j].push_back(i*m+j+1);
                        adj[i*m+j+1].push_back(i*m+j);
                    }
                    if(grid[i][j]==2) ini.push_back(i*m+j);
                }
            }
        }
        vector<int> dist=bfs(adj,ini);
        int maxdist=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]>=1){
                    if(dist[m*i+j]==-1) return -1;
                    else maxdist=max(maxdist,dist[m*i+j]);
                }
            }
        }
        return maxdist;
    }
};
