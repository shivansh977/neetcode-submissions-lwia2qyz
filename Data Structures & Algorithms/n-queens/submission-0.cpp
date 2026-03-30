class Solution {
private:
    bool isValidPlace(int n, int lvl, int i, vector<string>&board){
        for(int j=1;j<=n;j++){
            if(lvl-j>=0&&board[lvl-j][i]=='Q') return false;
            if(i-j>=0&&lvl-j>=0&&board[lvl-j][i-j]=='Q') return false;
            if(i+j<n&&lvl-j>=0&&board[lvl-j][i+j]=='Q') return false;
        }
        return true;
    }
    bool rec(int n,int lvl,vector<string>&board,vector<vector<string>>&fa){
        if(lvl==n){
            fa.push_back(board);
            return true;
        }
        bool fas=false;
        for(int i=0;i<n;i++){
            if(isValidPlace(n,lvl,i,board)){
                board[lvl][i]='Q';
                if(rec(n,lvl+1,board,fa)){
                    fas=true;
                }
                board[lvl][i]='.';
            }
        }
        return fas;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> fa;
        string x;
        for(int i=0;i<n;i++) x.push_back('.');
        vector<string> board(n,x);
        rec(n,0,board,fa);
        return fa;
    }
};
