class Solution {
private:
    void comb(vector<vector<int>>& fa, vector<int>& cur, int id, int n, int k){
        if(cur.size()+n-id<k) return;
        if(id==n){
            fa.push_back(cur);
        }
        if(cur.size()<k){
            cur.push_back(id+1);
            comb(fa,cur,id+1,n,k);
            cur.pop_back();
        }
        comb(fa,cur,id+1,n,k);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> fa;
        vector<int> cur;
        comb(fa,cur,0,n,k);
        return fa;
    }
};