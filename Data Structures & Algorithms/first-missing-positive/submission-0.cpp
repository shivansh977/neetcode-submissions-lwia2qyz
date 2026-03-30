class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int id=-1;
        int ans=1;
        while(true){
            bool flag=true;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==ans){
                    flag=false;
                    ans++;
                    break;
                }
            }
            if(flag) break;
        }
        return ans;
    }
};