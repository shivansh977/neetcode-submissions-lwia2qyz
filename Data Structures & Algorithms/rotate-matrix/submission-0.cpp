class Solution {
private:
    void rotateChunk(vector<vector<int>>& matrix, int i1, int j1, int i2, int j2){
        if(i1>=i2||j1>=j2||i1-i2!=j1-j2) return;
        vector<int> tmp;
        for(int j=j2;j>j1;j--){
            tmp.push_back(matrix[i2][j]);
            matrix[i2][j]=matrix[i1+(j2-j)][j2];
        }
        for(int i=i1;i<i2;i++){
            matrix[i][j2]=matrix[i1][j1+(i-i1)];
        }
        for(int j=j1;j<j2;j++){
            matrix[i1][j]=matrix[i2-(j-j1)][j1];
        }
        for(int i=i2;i>i1;i--){
            matrix[i][j1]=tmp[i2-i];
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            rotateChunk(matrix,i,i,n-1-i,n-1-i);
        }
    }
};
