class Solution {
private:
    bool canPartition(vector<int>& nums, vector<int>&subGrp, int grpSize, int id){
        if(id==nums.size()){
            return true;
        }
        bool ans=false;
        for(int i=0;i<subGrp.size();i++){
            if(subGrp[i]+nums[id]<=grpSize&&i<=id){
                subGrp[i]+=nums[id];
                ans=ans|canPartition(nums,subGrp,grpSize,id+1);
                subGrp[i]-=nums[id];
            }
        }
        return ans;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totsum=0;
        vector<int> subGrp(k,0);
        for(int x:nums) totsum+=x;
        if(totsum%k) return false;
        return canPartition(nums,subGrp,totsum/k,0);
    }
};