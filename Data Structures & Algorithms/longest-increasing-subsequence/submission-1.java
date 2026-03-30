class Solution {
    private int findLowerBound(List<Integer> nums, int val){
        int l=0;
        int r=nums.size()-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums.get(mid)<val) l=mid+1;
            else r=mid;
        }
        if(val>nums.get(l)) return -1;
        return l;
    }
    public int lengthOfLIS(int[] nums) {
        List<Integer> lis=new ArrayList();
        for(int i=0;i<nums.length;i++){
            if(lis.isEmpty()||nums[i]>lis.get(lis.size()-1)){
                lis.add(nums[i]);
            }
            else{
                int id=findLowerBound(lis, nums[i]);
                lis.set(id,nums[i]);
            }
        }
        return lis.size();
    }
}
