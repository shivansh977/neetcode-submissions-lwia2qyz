class Solution {
private:
    vector<int> topoSort(vector<vector<int>>& adj){
        int n=adj.size();
        vector<int> fa;
        vector<int> inDegree(n,0);
        for(int i=0;i<adj.size();i++){
            for(int v:adj[i]) inDegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int val=q.front();
            fa.push_back(val);
            q.pop();
            for(int v:adj[val]){
                inDegree[v]--;
                if(inDegree[v]==0) q.push(v);
            }
        }
        if(fa.size()==n) return fa;
        return {};
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> adj1(k);
        vector<vector<int>> adj2(k);
        vector<vector<int>> fa(k,vector<int>(k,0));
        for(const vector<int>& cond:rowConditions){
            adj1[cond[0]-1].push_back(cond[1]-1);
        }
        for(const vector<int>& cond:colConditions){
            adj2[cond[0]-1].push_back(cond[1]-1);
        }
        vector<int> rowSort=topoSort(adj1);
        vector<int> colSort=topoSort(adj2);
        if(rowSort.empty()||colSort.empty()) return {};
        vector<int> rowId(k);
        vector<int> colId(k);
        for(int i=0;i<rowSort.size();i++){
            rowId[rowSort[i]]=i;
        }
        for(int i=0;i<colSort.size();i++){
            colId[colSort[i]]=i;
        }
        for(int i=0;i<k;i++){
            fa[rowId[i]][colId[i]]=i+1;
        }
        return fa;
    }
};