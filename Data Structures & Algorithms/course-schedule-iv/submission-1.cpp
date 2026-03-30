class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isEdge(n,vector<bool>(n,false));
        vector<bool> fa;
        for(const vector<int>& v:prerequisites){
            isEdge[v[0]][v[1]]=true;
        }
        for(int kk=0;kk<n-1;kk++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        if(isEdge[i][k]&&isEdge[k][j]){
                            isEdge[i][j]=true;
                        }
                    }
                }
            }
        }
        for(const vector<int>&v:queries){
            fa.push_back(isEdge[v[0]][v[1]]);
        }
        return fa;
    }
};