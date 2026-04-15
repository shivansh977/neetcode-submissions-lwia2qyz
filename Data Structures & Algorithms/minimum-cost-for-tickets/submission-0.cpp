class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=min(min(costs[0],costs[1]),costs[2]);
        for(int i=1;i<n;i++){
            int id1=i;
            int id7=lower_bound(days.begin(),days.end(),days[i]-6)-days.begin();
            int id30=lower_bound(days.begin(),days.end(),days[i]-29)-days.begin();
            if(id1<=i){
                int val=id1==0?0:dp[id1-1];
                dp[i]=min(dp[i],val+costs[0]);
            }
            if(id7<=i){
                int val=id7==0?0:dp[id7-1];
                dp[i]=min(dp[i],val+costs[1]);
            }
            if(id30<=i){
                int val=id30==0?0:dp[id30-1];
                dp[i]=min(dp[i],val+costs[2]);
            }
        }
        return dp.back();
    }
};