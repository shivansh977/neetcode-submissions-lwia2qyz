class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<int> fa;
        int i=0,j=0;
        while(true){
            bool flag=false;
            while(j<m&&!vis[i][j]){
                fa.push_back(matrix[i][j]);
                vis[i][j++]=true;
                flag=true;
            }j--;i++;
            while(i<n&&!vis[i][j]){
                fa.push_back(matrix[i][j]);
                vis[i++][j]=true;
                flag=true;
            }i--;j--;
            while(j>=0&&!vis[i][j]){
                fa.push_back(matrix[i][j]);
                vis[i][j--]=true;
                flag=true;
            }j++;i--;
            while(i>=0&&!vis[i][j]){
                fa.push_back(matrix[i][j]);
                vis[i--][j]=true;
                flag=true;
            }i++;j++;
            if(!flag) break;
        }
        return fa;
    }
};
