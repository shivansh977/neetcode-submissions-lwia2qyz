class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        int n=nums1.size();
        int m=nums2.size();
        int lside=(n+m)/2;
        int l=0,r=n;
        int ans=0;
        double fa=INT_MAX;
        while(l<r){
            int x1=l+(r-l)/2;
            int x2=lside-x1;
            if(x2>0&&nums1[x1]<nums2[x2-1]){
                l=x1+1;
            }
            else if(x1>0&&nums2[x2]<nums1[x1-1]){
                r=x1-1;
            }
            else {
                ans=x1;break;
            }
        }
        if((n+m)%2){
            if(ans<n) fa=nums1[ans];
            if(lside-ans<m) fa=min(fa,(double)nums2[lside-ans]);
        }
        else{
            int val1=0,val2=INT_MAX;
            if(ans>0) val1=nums1[ans-1];
            if(lside-ans>0) val1=max(val1,nums2[lside-ans-1]);
            if(ans<n) val2=nums1[ans];
            if(lside-ans<m) val2=min(val2,nums2[lside-ans]);
            fa=1.0*(val1+val2)/2.0;
        }
        return fa;
    }
};
