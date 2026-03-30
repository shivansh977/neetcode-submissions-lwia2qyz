class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> fa;
        for(int i=0;i<nums.size();i++){
            if(fa.empty()||fa.back()!=nums[i]){
                fa.push_back(nums[i]);
            }
        }
        nums=fa;
        return nums.size();
    }
};