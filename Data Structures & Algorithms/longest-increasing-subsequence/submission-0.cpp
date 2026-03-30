class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            auto it=lower_bound(lis.begin(),lis.end(),nums[i]);
            if(it==lis.end()) lis.push_back(nums[i]);
            else lis[int(it-lis.begin())]=nums[i];
        }
        return lis.size();
    }
};
