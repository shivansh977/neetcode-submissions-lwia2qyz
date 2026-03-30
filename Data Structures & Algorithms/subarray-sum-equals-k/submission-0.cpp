class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        int ans=0;
        for(int en=0;en<nums.size();en++){
            for(int st=0;st<=en;st++){
                int val=0;
                if(st) val=nums[st-1];
                if(nums[en]-val==k) ans++;
            }
        }
        return ans;
    }
};