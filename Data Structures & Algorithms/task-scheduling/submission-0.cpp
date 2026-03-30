class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        priority_queue<pair<int,char>> pq;
        queue<pair<int,char>> q;
        int t=0;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        for(auto& p:m){
            if(p.second>0) pq.push({p.second,p.first});
        }
        while(!q.empty()||!pq.empty()){
            if(!pq.empty()){
                auto val=pq.top();
                pq.pop();
                m[val.second]--;
                if(m[val.second]>0) q.push({t,val.second});
            }
            while(!q.empty()&&q.front().first+n<=t){
                auto val=q.front();
                q.pop();
                if(m[val.second]>0) pq.push({m[val.second],val.second});
            }
            t++;
        }
        return t;

    }
};
