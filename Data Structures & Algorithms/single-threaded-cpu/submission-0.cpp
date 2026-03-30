struct Compare{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if(a.first!=b.first){
            return a.first>b.first;
        }
        return a.second>b.second;
    }
};
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        vector<int> fa;
        int curtime=tasks[0][0];
        int l=1;
        pq.push({tasks[0][1],tasks[0][2]});
        while(!pq.empty()){
            pair<int,int> task=pq.top();
            pq.pop();
            curtime+=task.first;
            int l1=l;
            while(l<tasks.size()&&tasks[l][0]<=curtime){
                pq.push({tasks[l][1],tasks[l][2]});
                l++;
            }
            if(l<tasks.size()&&l1==l){
                pq.push({tasks[l][1],tasks[l][2]});
                l++;
                curtime=max(curtime,tasks[l][0]);
            } 
            fa.push_back(task.second);
        }
        return fa;
    }
};