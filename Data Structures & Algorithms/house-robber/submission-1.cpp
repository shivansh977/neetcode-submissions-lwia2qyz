class Solution {
public:
    int rob(vector<int>& nums) {
        nums[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            nums[i]+=nums[i-2];
            nums[i]=max(nums[i],nums[i-1]);
        }
        return nums.back();
    }
};
