class Solution {
private:
    int rob1(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        nums[1]=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            nums[i]+=nums[i-2];
            nums[i]=max(nums[i],nums[i-1]);
        }
        return nums.back();
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> nums1,nums2;
        for(int i=0;i<nums.size()-1;i++){
            nums1.push_back(nums[i]);
            nums2.push_back(nums[i+1]);
        }
        return max(rob1(nums1),rob1(nums2));
    }
};
