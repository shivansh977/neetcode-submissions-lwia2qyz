class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> cnt1(10,vector<int>(10,0));
        vector<vector<int>> cnt2(10,vector<int>(10,0));
        vector<vector<int>> cnt3(10,vector<int>(10,0));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int x=int(board[i][j]-'0');
                if(x>=0&&x<=9){
                    cnt1[i][x]++;
                    cnt2[j][x]++;
                    cnt3[(i/3)+3*(j/3)][x]++;
                }
            }
        }
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                if(cnt1[i][j]>1||cnt2[i][j]>1||cnt3[i][j]>1) return false;
            }
        }
        return true;
    }
};
