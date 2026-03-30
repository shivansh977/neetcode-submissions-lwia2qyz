class DSU{
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findParent(int x){
        if(parent[x]==x) return x;
        return parent[x]=findParent(parent[x]);
    }
    void unionAll(int x, int y){
        int xrep=findParent(x);
        int yrep=findParent(y);
        if(xrep == yrep) return;
        if(rank[xrep]>rank[yrep]){
            parent[yrep]=xrep;
        }
        else if(rank[xrep]<rank[yrep]){
            parent[xrep]=yrep;
        }
        else{
            parent[xrep]=yrep;
            rank[yrep]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            if(dsu.findParent(edges[i][0]-1)==dsu.findParent(edges[i][1]-1)){
                ans=edges[i];
            }
            else dsu.unionAll(edges[i][0]-1,edges[i][1]-1);
        }
        return ans;
    }
};