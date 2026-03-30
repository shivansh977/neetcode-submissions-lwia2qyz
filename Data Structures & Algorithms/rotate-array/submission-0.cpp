class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==0) return;
        vector<int> temp;
        vector<int> fa;
        for(int i=0;i<k;i++){
            temp.push_back(nums.back());
            nums.pop_back();
        }
        while(!temp.empty()){
            fa.push_back(temp.back());
            temp.pop_back();
        }
        for(int val:nums) fa.push_back(val);
        nums=fa;
    }
};