class Solution {
private:
    bool hasCycle(int node, vector<bool>&vis, vector<bool>&inStack, vector<vector<int>>&adj){
        vis[node]=true;
        inStack[node]=true;
        for(int i=0;i<adj[node].size();i++){
            if((!vis[adj[node][i]]&&hasCycle(adj[node][i],vis,inStack,adj))||inStack[adj[node][i]]){
                return true;
            }
        }
        inStack[node]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses,false);
        vector<bool> inStack(numCourses,false);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]&&hasCycle(i,vis,inStack,adj)) return false; 
        }
        return true;
    }
};
