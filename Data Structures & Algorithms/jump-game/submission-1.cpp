class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size()-1;i++){
            nums[i]=nums[i]+i;
            if(i>0){
                if(nums[i-1]<i) return false;
                nums[i]=max(nums[i],nums[i-1]);
            }
        }
        return nums[nums.size()-2]>=nums.size()-1;
    }
};
