class Solution {
private:
    int maxP(vector<int>&nums, int st, int en){
        if(st==en) return nums[st];
        int ans=1;
        for(int i=st;i<=en;i++) ans*=nums[i];
        if(ans>=0) return ans;
        int ans1=ans;
        for(int i=st;i<=en;i++){
            ans/=nums[i];
            if(nums[i]<0) break;
        }
        for(int i=en;i>=st;i--){
            ans1/=nums[i];
            if(nums[i]<0) break;
        }
        return max(ans,ans1);
    }
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int fa=INT_MIN;
        vector<vector<int>> inter;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(inter.empty()||inter.back().back()+1!=i){
                    inter.push_back({i,i});
                }
                else inter.back().back()++;
            }
            else fa=max(fa,0);
        }
        for(int i=0;i<inter.size();i++){
            fa=max(fa,maxP(nums,inter[i][0],inter[i][1]));
        }
        return fa;
    }
};
