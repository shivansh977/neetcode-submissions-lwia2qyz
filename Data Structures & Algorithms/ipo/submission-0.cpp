class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> pc;
        priority_queue<int> pq;
        for(int i=0;i<profits.size();i++){
            pc.push_back({capital[i],profits[i]});
        }
        sort(pc.begin(),pc.end());
        int id=0;
        int psize=0;
        while(psize<k){
            while(id<profits.size()&&pc[id].first<=w){
                pq.push(pc[id].second);
                id++;
            }
            if(pq.empty()) break;
            w+=pq.top();
            psize++;
            pq.pop();
        }
        return w;
    }
};