class Solution {
private:
    bool exists(vector<vector<char>>& board, vector<vector<bool>>& vis, string& word, int id, int i, int j){
        if(id==word.length()) return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||vis[i][j]||word[id]!=board[i][j]){
            return false;
        }
        vis[i][j]=true;
        bool ans=false;
        ans=ans|exists(board,vis,word,id+1,i-1,j);
        ans=ans|exists(board,vis,word,id+1,i,j-1);
        ans=ans|exists(board,vis,word,id+1,i+1,j);
        ans=ans|exists(board,vis,word,id+1,i,j+1);
        vis[i][j]=false;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=ans|exists(board,vis,word,0,i,j);
            }
        }
        return ans;
    }
};
