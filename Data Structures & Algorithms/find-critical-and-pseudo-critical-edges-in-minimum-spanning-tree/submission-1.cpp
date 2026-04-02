class DSU{
private:
    vector<int> rank;
    vector<int> parent;
public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i; 
    }
    int find(int k){
        if(k!=parent[k]){
            return parent[k]=find(parent[k]);
        }
        return k;
    }
    void unionAll(int a, int b){
        int n=rank.size();
        if(a>=n||b>=n) return;
        int aRep=parent[a];
        int bRep=parent[b];
        if(aRep==bRep) return;
        if(rank[aRep]>rank[bRep]){
            parent[bRep]=aRep;
        }
        else if(rank[aRep]<rank[bRep]) parent[aRep]=bRep;
        else{
            parent[bRep]=aRep;
            rank[aRep]++;
        }
    }
};
bool cmp(vector<int>& a, vector<int>& b){
    if(a[2]!=b[2]) return a[2]<b[2];
    else if(a[1]!=b[1]) return a[1]<b[1];
    return a[0]<b[0];
}
class Solution {
private:
    int findMST(vector<vector<int>>& edges, DSU& dsu, int n, int id){
        int fa=0;
        for(int i=0;i<edges.size();i++){
            if(id!=i&&dsu.find(edges[i][0])!=dsu.find(edges[i][1])){
                dsu.unionAll(edges[i][0],edges[i][1]);
                fa+=edges[i][2];
            }  
        }
        int tmp=dsu.find(0);
        for(int i=0;i<n;i++){
            if(tmp!=dsu.find(i)) return -1;
        }
        return fa;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        vector<int> critical;
        vector<int> pCritical;
        sort(edges.begin(),edges.end(),cmp);
        DSU dsu(n);
        int mst=findMST(edges,dsu,n,-1);
        for(int i=0;i<edges.size();i++){
            DSU dsu1(n);
            DSU dsu2(n);
            dsu2.unionAll(edges[i][0],edges[i][1]);
            int tval=findMST(edges,dsu1,n,i);
            int tval1=findMST(edges,dsu2,n,i)+edges[i][2];
            if(tval==-1||tval>mst){
                critical.push_back(edges[i].back());
            }
            else if(tval1==mst){
                pCritical.push_back(edges[i].back());
            }
        }
        return {critical, pCritical};

    }
};