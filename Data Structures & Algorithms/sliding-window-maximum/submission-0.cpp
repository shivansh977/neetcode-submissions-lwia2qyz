class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty()&&nums[i]>dq.back().first){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
        }
        vector<int> ans={dq.front().first};
        for(int i=k;i<nums.size();i++){
            while(!dq.empty()&&dq.front().second<=i-k){
                dq.pop_front();
            }
            while(!dq.empty()&&nums[i]>dq.back().first){
                dq.pop_back();
            }
            dq.push_back({nums[i],i});
            ans.push_back(dq.front().first);
        }
        return ans;
    }
};
