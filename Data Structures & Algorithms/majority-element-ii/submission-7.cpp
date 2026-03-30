class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size()<=2) return nums;
        int val1=-1;
        int val2=-1;
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(cnt1>0&&nums[i]==val1){
                cnt1++;
            }
            else if(cnt2>0&&nums[i]==val2){
                cnt2++;
            }
            else if(cnt1==0){
                val1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                val2=nums[i];
                cnt2=1;
            }
            else{
                cnt2--;
                cnt1--;
            }
        }
        int n = nums.size();
        int c1 = 0, c2 = 0;
        for (int x : nums) {
            if (x == val1) c1++;
            else if (x == val2) c2++;
        }

        vector<int> res;
        if (c1 > n / 3) res.push_back(val1);
        if (c2 > n / 3) res.push_back(val2);

        return res;
    }
};