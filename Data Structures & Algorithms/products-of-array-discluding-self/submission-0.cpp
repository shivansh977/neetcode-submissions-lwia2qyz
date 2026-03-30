#define ll long long
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> fa(n,0);
        int cnt0=0;int id0=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) {cnt0++;id0=i;}
        }
        if(cnt0>1) return fa;
        else if(cnt0==1){
            int tmp=1;
            for(int i=0;i<nums.size();i++){
                if(i!=id0) tmp*=nums[i];
            }fa[id0]=tmp;
            return fa;
        }
        else{
            ll prod=1LL;
            for(int i=0;i<nums.size();i++){
                prod*=(ll)nums[i];
            }
            for(int i=0;i<nums.size();i++){
                fa[i]=int(prod/(ll)(nums[i]));
            }
            return fa;
        }
        return fa;
    }
};
