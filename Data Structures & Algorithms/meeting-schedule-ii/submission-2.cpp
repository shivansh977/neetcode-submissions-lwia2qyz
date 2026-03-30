/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
bool comp(Interval& a, Interval& b){
    if(a.end<b.end||(a.end==b.end&&a.start<b.start)) return true;
    return false;
}
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<Interval>> fa;
        if(intervals.empty()) return 0;
        fa.push_back({intervals[0]});
        for(int i=1;i<intervals.size();i++){
            int id=-1;
            for(int j=fa.size()-1;j>=0;j--){
                if(fa[j].back().end<=intervals[i].start){
                    id=j;break;
                }
            }
            if(id==-1) fa.push_back({intervals[i]});
            else fa[id].push_back(intervals[i]);
        }
        return fa.size();
    }
};
