class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int x:nums){
            if(m[x]) return true;
            m[x]++;
        }
        return false;
    }
};