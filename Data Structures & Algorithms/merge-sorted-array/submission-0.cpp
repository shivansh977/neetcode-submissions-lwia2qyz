class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        swap(n,m);
        vector<int> nums;
        while(i<n||j<m){
            if(i<n&&j<m){
                if(nums1[i]<nums2[j]){
                    nums.push_back(nums1[i++]);
                }
                else{
                    nums.push_back(nums2[j++]);
                }
            }
            else if(i<n){
                nums.push_back(nums1[i++]);
            }
            else {
                nums.push_back(nums2[j++]);
            }
        }
        nums1=nums;
    }
};