class Solution {
private:
    void heapify(vector<int>& arr, int n, int i){
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<n&&arr[l]>arr[largest]){
            largest=l;
        }
        if(r<n&&arr[r]>arr[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(nums,n,i);
        }
        for(int i=n-1;i>=1;i--){
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
        return nums;
    }
};