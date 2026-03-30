class Solution {
private:
    void dfs(int node, vector<bool>&vis, vector<vector<int>>&adj){
        if(vis[node]) return;
        vis[node]=true;
        for(int n:adj[node]){
            dfs(n,vis,adj);
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) {dfs(i,vis,adj);ans++;}
        }
        return ans;
    }
};
