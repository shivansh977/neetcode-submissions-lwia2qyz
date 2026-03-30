class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        int ans=0;
        unordered_map<int,int> m;
        if(nums[0]==k) ans++;
        m[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==k) ans++;
            ans+=m[nums[i]-k];
            m[nums[i]]++;
        }
        return ans;
    }
};