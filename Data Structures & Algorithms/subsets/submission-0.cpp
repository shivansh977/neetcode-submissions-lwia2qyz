class Solution {
private:
    void findSubs(vector<int> cur, vector<int>& nums, int id, vector<vector<int>>& fa){
        if(id==nums.size()){
            fa.push_back(cur);
            return;
        }
        cur.push_back(nums[id]);
        findSubs(cur,nums,id+1,fa);
        cur.pop_back();
        findSubs(cur,nums,id+1,fa);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> fa;
        vector<int> cur;
        findSubs(cur,nums,0,fa);
        return fa;
    }
};
