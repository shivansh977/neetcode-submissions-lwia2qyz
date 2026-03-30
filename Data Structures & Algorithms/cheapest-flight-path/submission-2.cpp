class Solution {
private:
    void dijk(vector<vector<pair<int,int>>>&adj, vector<vector<int>>& dist, int src, int k){
        dist[src][0]=0;
        priority_queue<vector<int>> pq;
        pq.push({0,0,src});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(x[1]>k) continue;
            for(auto n:adj[x[2]]){
                if(dist[n.first][x[1]+1]>-x[0]+n.second){
                    dist[n.first][x[1]+1]=-x[0]+n.second;
                    pq.push({x[0]-n.second,x[1]+1,n.first});
                }
            }
        }
        
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        for(auto f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        dijk(adj,dist,src,k);
        int ans=INT_MAX;
        for(int i=0;i<dist[dst].size();i++) ans=min(ans,dist[dst][i]);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
