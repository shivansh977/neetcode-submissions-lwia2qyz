class Solution {
private:
    void subsets(vector<int>& nums, vector<vector<int>>& fa, vector<int>& cur, int id){
        if(id==nums.size()){
            fa.push_back(cur);
            return;
        }
        cur.push_back(nums[id]);
        subsets(nums,fa,cur,id+1);
        cur.pop_back();
        subsets(nums,fa,cur,id+1);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> fa;
        vector<vector<int>> fa1;
        vector<int> cur;
        subsets(nums,fa,cur,0);
        for(int i=0;i<fa.size();i++){
            sort(fa[i].begin(),fa[i].end());
        }
        sort(fa.begin(),fa.end());
        for(int i=0;i<fa.size();i++){
            if(fa1.empty()||fa1.back()!=fa[i]){
                fa1.push_back(fa[i]);
            }
        }
        return fa1;
    }
};
