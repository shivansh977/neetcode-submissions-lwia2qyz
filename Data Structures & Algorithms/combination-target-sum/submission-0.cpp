class Solution {
private:
    void findVals(vector<vector<int>>&fa, vector<int> &cur, int sum, int target, vector<int>&nums){
        if(sum>target) return;
        if(sum==target){
            fa.push_back(cur);
        }
        for(int i=0;i<nums.size();i++){
            if(cur.empty()||nums[i]>=cur.back()){
                cur.push_back(nums[i]);
                findVals(fa,cur,sum+nums[i],target,nums);
                cur.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> fa;
        vector<int> cur;
        findVals(fa,cur,0,target,nums);
        return fa;
    }
};
