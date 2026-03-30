class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<vector<int>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            vector<int> x=pq.top();
            pq.pop();
            int d=-x[0];
            if(dist[x[1]][x[2]]<d){
                continue;
            }
            if(x[1]>0){
                if(dist[x[1]-1][x[2]]>max(d,abs(heights[x[1]-1][x[2]]-heights[x[1]][x[2]]))){
                    dist[x[1]-1][x[2]]=max(d,abs(heights[x[1]-1][x[2]]-heights[x[1]][x[2]]));
                    pq.push({-dist[x[1]-1][x[2]],x[1]-1,x[2]});
                }
            }
            if(x[2]>0){
                if(dist[x[1]][x[2]-1]>max(d,abs(heights[x[1]][x[2]-1]-heights[x[1]][x[2]]))){
                    dist[x[1]][x[2]-1]=max(d,abs(heights[x[1]][x[2]-1]-heights[x[1]][x[2]]));
                    pq.push({-dist[x[1]][x[2]-1],x[1],x[2]-1});
                }
            }
            if(x[1]<n-1){
                if(dist[x[1]+1][x[2]]>max(d,abs(heights[x[1]+1][x[2]]-heights[x[1]][x[2]]))){
                    dist[x[1]+1][x[2]]=max(d,abs(heights[x[1]+1][x[2]]-heights[x[1]][x[2]]));
                    pq.push({-dist[x[1]+1][x[2]],x[1]+1,x[2]});
                }
            }
            if(x[2]<m-1){
                if(dist[x[1]][x[2]+1]>max(d,abs(heights[x[1]][x[2]+1]-heights[x[1]][x[2]]))){
                    dist[x[1]][x[2]+1]=max(d,abs(heights[x[1]][x[2]+1]-heights[x[1]][x[2]]));
                    pq.push({-dist[x[1]][x[2]+1],x[1],x[2]+1});
                }
            }
        }
        return dist.back().back();
    }
};