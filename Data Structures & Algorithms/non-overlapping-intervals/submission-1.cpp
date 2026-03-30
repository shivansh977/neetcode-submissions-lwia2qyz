bool comp(vector<int>& a, vector<int>& b){
    if(a[1]<b[1]) return true;
    else if(a[1]==b[1]&&a[0]<b[0]) return true;
    return false;
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> fa;
        fa.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(fa.back()[1]>intervals[i][0]){
                ans++;
            }
            else fa.push_back(intervals[i]);
        }
        return ans;
    }
};
