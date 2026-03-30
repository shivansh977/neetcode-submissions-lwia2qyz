class Solution {
private:
    void subset(vector<int>& nums, vector<int>& cur, int id, int& ans){
        if(id==nums.size()){
            int tmp=0;
            for(int x:cur) tmp=tmp^x;
            ans+=tmp;
            return;
        }
        cur.push_back(nums[id]);
        subset(nums,cur,id+1,ans);
        cur.pop_back();
        subset(nums,cur,id+1,ans);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        vector<int> cur;
        subset(nums,cur,0,ans);
        return ans;
    }
};