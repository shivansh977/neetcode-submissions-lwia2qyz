class Solution {
private:
    int binSearch(vector<int>& nums, int st, int en, int target){
        while(st<=en){
            int mid=st+(en-st)/2;
            if(nums[mid]<target){
                st=mid+1;
            }
            else if(nums[mid]>target){
                en=mid-1;
            }
            else return mid;
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums.back()) l=mid+1;
            else r=mid;
        }
        if(l==0){
            return binSearch(nums,0,n-1,target);
        }
        int v1=binSearch(nums,0,l-1,target);
        int v2=binSearch(nums,l,n-1,target);
        if(v1!=-1) return v1;
        if(v2!=-1) return v2;
        return -1; 
    }
};
