class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else r=mid;
        }
        return nums[l];
    }
};

//3 4 5 6 7 8 9 10 0 1 2

