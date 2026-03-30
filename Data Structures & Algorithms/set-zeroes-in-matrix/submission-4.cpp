class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool fr=false,fc=false;
        for(int j=0;j<matrix[0].size();j++) fr=fr|matrix[0][j]==0;
        for(int i=0;i<matrix.size();i++) fc=fc|matrix[i][0]==0;
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][j]=1;
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                for(int j=0;j<matrix[0].size();j++) matrix[i][j]=0;
            }
        }
        for(int j=1;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                for(int i=0;i<matrix.size();i++) matrix[i][j]=0;
            }
        }
        if(fr) for(int j=0;j<matrix[0].size();j++) matrix[0][j]=0;
        if(fc) for(int i=0;i<matrix.size();i++) matrix[i][0]=0;
    }
};
