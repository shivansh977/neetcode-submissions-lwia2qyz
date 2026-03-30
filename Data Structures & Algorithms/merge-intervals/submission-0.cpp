class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> fa;
        fa.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(fa.back()[1]>=intervals[i][0]){
                fa.back()[1]=max(fa.back()[1],intervals[i][1]);
            }
            else fa.push_back(intervals[i]);
        }
        return fa;
    }
};
