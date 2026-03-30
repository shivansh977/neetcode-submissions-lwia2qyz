#define ll int long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> fa;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-2;j++){
                int x=j+1;
                int y=n-1;
                ll tar=(ll)target-(ll)nums[i]-(ll)nums[j];
                while(x<y){
                    if((ll)nums[x]+(ll)nums[y]<tar){
                        x++;
                    }
                    else if((ll)nums[x]+(ll)nums[y]>tar){
                        y--;
                    }
                    else{
                        vector<int> tmp={nums[i],nums[j],nums[x],nums[y]};
                        fa.insert(tmp);
                        x++;
                        y--;
                    }
                }
            }
        }
        vector<vector<int>> ffa;
        for(const vector<int>& x:fa){
            ffa.push_back(x);
        }
        return ffa;
    }
};