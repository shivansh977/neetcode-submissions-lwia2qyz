class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        for(int i=intervals.size()-2;i>=0;i--){
            if(intervals[i+1][0]<intervals[i][0]){
                swap(intervals[i+1],intervals[i]);
            }
            else break;
        }
        vector<vector<int>> fa;
        fa.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=fa.back()[1]){
                fa.back()[1]=max(fa.back()[1], intervals[i][1]);
            }
            else{
                fa.push_back(intervals[i]);
            }
        }
        return fa;
    }
};
