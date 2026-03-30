class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n,0);
        vector<int> outDegree(n,0);
        for(vector<int>& edge:trust){
            outDegree[edge[0]-1]++;
            inDegree[edge[1]-1]++;
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]==n-1&&outDegree[i]==0) return i+1;
        }
        return -1;
    }
};