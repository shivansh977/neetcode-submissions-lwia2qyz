class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> fa;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int target=-nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]>target){
                    k--;
                }
                else if(nums[j]+nums[k]<target){
                    j++;
                }
                else{
                    vector<int> ans={nums[i],nums[j],nums[k]};
                    fa.push_back(ans);
                    j++;k--;
                }
            }
        }
        sort(fa.begin(),fa.end());
        if(fa.empty()) return fa;
        vector<vector<int>> fa1={fa[0]};
        for(int i=1;i<fa.size();i++){
            if(fa[i]!=fa1.back()) fa1.push_back(fa[i]);
        }
        return fa1;
    }
};
