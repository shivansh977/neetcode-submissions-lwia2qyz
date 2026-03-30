class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> freq;
        vector<int> fa;
        vector<pair<int,int>> freq_cnt;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(auto it=freq.begin();it!=freq.end();it++){
            freq_cnt.push_back({it->second,it->first});
        }
        sort(freq_cnt.begin(),freq_cnt.end());
        int n=freq_cnt.size();
        for(int i=0;i<k;i++){
            fa.push_back(freq_cnt[n-1-i].second);
        }
        return fa;
    }
};
