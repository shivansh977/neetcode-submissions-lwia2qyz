class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,sum=0,ans=INT_MAX; 
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(l<=r&&sum-nums[l]>=target){
                sum-=nums[l++];
            }
            if(sum>=target){
                ans=min(ans,r-l+1);
            }
        }
        if(ans==INT_MAX) ans=0;
        return ans;
    }
};