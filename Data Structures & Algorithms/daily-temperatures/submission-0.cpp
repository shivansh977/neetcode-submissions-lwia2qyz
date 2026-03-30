class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> fa(n,0);
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++){
            while(!s.empty()&&s.top().first<temperatures[i]){
                fa[s.top().second]=i-s.top().second;
                s.pop();
            }
            s.push({temperatures[i],i});
        }
        return fa;
    }
};
