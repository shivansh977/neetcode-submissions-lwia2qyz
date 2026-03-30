class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int val=-1;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                cnt++;
            }
            else if(cnt==0){
                val=nums[i];
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return val;
    }
};