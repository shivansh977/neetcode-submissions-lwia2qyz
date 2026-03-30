class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> fa;
        for(int x:nums){
            if(x!=val) fa.push_back(x);
        }
        nums=fa;
        return fa.size();
    }
};