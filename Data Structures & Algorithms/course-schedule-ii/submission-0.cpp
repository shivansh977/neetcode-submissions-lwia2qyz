class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inDegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<adj.size();i++){
            if(inDegree[i]==0) q.push(i);
        }
        vector<int> fa;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            fa.push_back(node);
            for(int n:adj[node]){
                inDegree[n]--;
                if(inDegree[n]==0){
                    q.push(n);
                }
            }
        }
        vector<int> emptyArray;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]) return emptyArray;
        }
        return fa;
    }
};
