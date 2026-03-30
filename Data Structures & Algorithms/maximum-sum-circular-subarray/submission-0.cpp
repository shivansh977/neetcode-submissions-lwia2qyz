class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cursum=0;
            for(int j=i;j<i+n;j++){
                cursum+=nums[j%n];
                ans=max(ans,cursum);
            }
        }
        return ans;
    }
};