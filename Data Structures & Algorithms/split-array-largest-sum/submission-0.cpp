class Solution {
private:
    bool good(vector<int>& nums, int k, int ans){
        int cnt=1;
        int cur=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>ans) return false;
            if(cur+nums[i]>ans){
                cur=nums[i];
                cnt++;
            }
            else cur+=nums[i];
        }
        return cnt<=k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int l=0,r=1e9;
        while(l<r){
            int mid=l+(r-l)/2;
            if(good(nums,k,mid)){
                r=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};