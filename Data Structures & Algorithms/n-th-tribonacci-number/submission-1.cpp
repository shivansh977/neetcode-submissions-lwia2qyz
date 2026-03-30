class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp={0,1,1};
        if(n<=2) return dp[n];
        for(int i=0;i<=n-3;i++){
            int x=dp.size();
            dp.push_back(dp[x-1]+dp[x-2]+dp[x-3]);
        }
        return dp.back();
    }
};