class Solution {
private:
    void dijk(vector<vector<pair<int,int>>>&adj, vector<int>&dist, int st){
        dist[st]=0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,st});
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            int d=-x.first;
            int n=x.second;
            for(auto node: adj[n]){
                if(dist[node.first]>d+node.second){
                    dist[node.first]=d+node.second;
                    pq.push({-dist[node.first],node.first});
                }
            }
        }
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> dist(n,INT_MAX);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        dijk(adj,dist,k-1);
        int ans=0;
        for(int i=0;i<dist.size();i++){
            int val=dist[i];
            if(val==INT_MAX) return -1;
            ans=max(ans,val);
        }
        return ans;
    }
};
