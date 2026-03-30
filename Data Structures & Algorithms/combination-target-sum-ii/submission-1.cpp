class Solution {
private:
    void findSum(vector<vector<int>>& fa, vector<int>& cur, int sum, int target, vector<int>&candidates){
        if(sum>target) return;
        else if(sum==target) {fa.push_back(cur);return;}
        for(int i=0;i<candidates.size();i++){
            if(cur.empty()||i>cur.back()){
                cur.push_back(i);
                findSum(fa,cur,sum+candidates[i],target,candidates);
                cur.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> fa;
        vector<int> cur;
        findSum(fa,cur,0,target,candidates);
        for(int i=0;i<fa.size();i++){
            for(int j=0;j<fa[i].size();j++){
                fa[i][j]=candidates[fa[i][j]];
            }
        }
        for(int i=0;i<fa.size();i++){
            sort(fa[i].begin(),fa[i].end());
        }
        sort(fa.begin(),fa.end());
        vector<vector<int>> fa1;
        if(fa.empty()) return fa;
        fa1.push_back(fa[0]);
        for(int i=1;i<fa.size();i++){
            if(fa[i]!=fa1.back()) fa1.push_back(fa[i]);
        }
        return fa1;
    }
};
