class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,pair<int,int>> spec;
        int maxans=0;
        for(int i=0;i<nums.size();i++){
            //spec[nums[i]]={nums[i],nums[i]};
            int highval=nums[i], lowval=nums[i];
            while(spec.find(highval+1)!=spec.end()){
                highval=spec[highval+1].second;
            }
            while(spec.find(lowval-1)!=spec.end()){
                lowval=spec[lowval-1].first;
            }
            maxans=max(maxans,highval-lowval+1);
            spec[nums[i]]={lowval,highval};
        }
        return maxans;
    }
};
