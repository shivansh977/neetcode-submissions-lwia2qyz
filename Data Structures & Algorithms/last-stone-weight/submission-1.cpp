class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x:stones) pq.push(x);
        int fa=0;
        while(pq.size()>1){
            int v1=pq.top();pq.pop();
            int v2=pq.top();pq.pop();
            if(v1-v2) pq.push(v1-v2);
        }
        return pq.empty()?0:pq.top();
    }
};
