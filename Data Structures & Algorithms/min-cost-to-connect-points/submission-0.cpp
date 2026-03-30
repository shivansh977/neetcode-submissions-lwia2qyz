class DSU{
private:
    vector<int> rank;
    vector<int> parent;
public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int a){
        if(parent[a]!=a){
            return parent[a]=find(parent[a]);
        }
        return a;
    }
    void unionAll(int a, int b){
        int aRep=find(a);
        int bRep=find(b);
        if(rank[aRep]>rank[bRep]){
            parent[bRep]=aRep;
        }
        else if(rank[bRep]>rank[aRep]){
            parent[aRep]=bRep;
        }
        else{
            parent[aRep]=bRep;
            rank[bRep]++;
        }
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        DSU dsu(n);
        priority_queue<vector<int>> pq;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                pq.push({-abs(points[j][1]-points[i][1])-abs(points[j][0]-points[i][0]),
                i,j});
            }
        }
        int totans=0;
        while(!pq.empty()){
            vector<int> x=pq.top();
            pq.pop();
            if(dsu.find(x[1])==dsu.find(x[2])){
                continue;
            }
            totans-=x[0];
            dsu.unionAll(x[1],x[2]);
        }
        return totans;
    }
};
