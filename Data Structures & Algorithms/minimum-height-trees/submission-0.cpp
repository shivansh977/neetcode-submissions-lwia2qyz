class Solution {
private:
    void rec(int id, int st, vector<vector<int>>& adj, vector<vector<int>>& dist, vector<bool>& vis){
        queue<int> q;
        q.push(st);
        vis[st]=true;
        dist[id][st]=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int neigh:adj[x]){
                if(!vis[neigh]){
                    dist[id][neigh]=dist[id][x]+1;
                    vis[neigh]=true;
                    q.push(neigh);
                }
            }
        }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const vector<int>& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> leaves;
        for(int i=0;i<n;i++){
            if(adj[i].size()==1) leaves.push_back(i);
        }
        int m=leaves.size();
        vector<vector<int>> dist(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            vector<bool> vis(n,false);
            rec(i,leaves[i],adj,dist,vis);
        }
        vector<int> maxdist(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxdist[i]=max(maxdist[i],dist[j][i]);
            }
        }
        int minval=maxdist[0];
        for(int i=0;i<n;i++){
            minval=min(minval,maxdist[i]);
        }
        vector<int> fa;
        for(int i=0;i<n;i++) if(maxdist[i]==minval) fa.push_back(i);
        return fa;
    }
};