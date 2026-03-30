class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> fa;
        for(int i=0;i<points.size();i++){
            pq.push({-(points[i][0]*points[i][0]+points[i][1]*points[i][1]),{points[i][0],points[i][1]}});
        }
        for(int i=0;i<k;i++){
            auto val=pq.top();
            pq.pop();
            fa.push_back({val.second.first,val.second.second});
        }
        return fa;
    }
};
