class Solution {
private:
    void dfs(vector<vector<int>>&adj,vector<bool>&vis,int node){
        if(vis[node]) return;
        vis[node]=true;
        for(int n:adj[node]){
            dfs(adj,vis,n);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<bool> vis(n*m,false);
        vector<vector<int>> adj(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    if(i+1<n&&board[i+1][j]=='O'){
                        adj[m*i+j].push_back(m*(i+1)+j);
                        adj[m*(i+1)+j].push_back(m*i+j);
                    }
                    if(j+1<m&&board[i][j+1]=='O'){
                        adj[m*i+j].push_back(m*i+j+1);
                        adj[m*i+j+1].push_back(m*i+j);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(adj,vis,m*i);
            if(board[i][m-1]=='O') dfs(adj,vis,i*m+m-1);
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O') dfs(adj,vis,i);
            if(board[n-1][i]=='O') dfs(adj,vis,(n-1)*m+i);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&!vis[m*i+j]) board[i][j]='X';
            }
        }
    }
};
