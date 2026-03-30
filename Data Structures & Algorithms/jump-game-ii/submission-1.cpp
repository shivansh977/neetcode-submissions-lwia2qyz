class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=i;
            nums[i]=max(nums[i],nums[i-1]);
        }
        int id=0;int ans=0;
        while(id<nums.size()-1){
            id=nums[id];ans++;
        }
        return ans;
    }
};
