class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxa=0;
        stack<pair<int,int>> s,s1;
        vector<pair<int,int>> spec(n,{0,n-1});
        for(int i=0;i<n;i++){
            while(!s.empty()&&s.top().first>heights[i]){
                spec[s.top().second].second=i-1;
                s.pop();
            }
            s.push({heights[i],i});
        }
        for(int i=n-1;i>=0;i--){
            while(!s1.empty()&&s1.top().first>heights[i]){
                spec[s1.top().second].first=i+1;
                s1.pop();
            }
            s1.push({heights[i],i});
        }
        for(int i=0;i<n;i++){
            //cout<<spec[i].first<<" "<<spec[i].second<<"\n";
            maxa=max(maxa,(spec[i].second-spec[i].first+1)*heights[i]);
        }
        return maxa;
    }
};
