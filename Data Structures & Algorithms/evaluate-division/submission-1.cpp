class Solution {
private:
    vector<pair<int,double>> adj[50];
    void dfs(int st, int curnode, vector<vector<double>>& dp, double curval, vector<bool>& vis){
        if(vis[curnode]) return;
        vis[curnode]=true;
        dp[st][curnode]=curval;
        for(const auto& neigh:adj[curnode]){
            dfs(st,neigh.first,dp,curval*neigh.second,vis);
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<vector<double>> dp(50,vector<double>(50,-1));
        for(int i=0;i<20;i++) dp[i][i]=0;
        map<string,int> m;
        int cnt=0;
        for(int i=0;i<equations.size();i++){
            int n1,n2;
            if(!m.count(equations[i][0])){
                m[equations[i][0]]=cnt++;
            }
            if(!m.count(equations[i][1])){
                m[equations[i][1]]=cnt++;
            }
            n1=m[equations[i][0]];
            n2=m[equations[i][1]];
            if(n1==n2) continue;
            adj[n1].push_back({n2,values[i]});
            adj[n2].push_back({n1,1.0/(values[i]*1.0)});
        }
        for(int i=0;i<cnt;i++){
            vector<bool> vis(cnt,false);
            dfs(i,i,dp,1.0,vis);
        }
        vector<double> fa;
        for(int i=0;i<queries.size();i++){
            int n1=-1,n2=-1;
            if(m.count(queries[i][0])) n1=m[queries[i][0]];
            if(m.count(queries[i][1])) n2=m[queries[i][1]];
            if(n1!=-1&&n2!=-1) fa.push_back(dp[n1][n2]);
            else fa.push_back(-1.0);
        }
        return fa;
    }
};