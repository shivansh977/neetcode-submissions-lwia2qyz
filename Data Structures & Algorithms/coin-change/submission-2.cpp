#define ll int long long
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<ll> dp(amount+1,INT_MAX);
        dp[0]=0LL;
        for(int i=0;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i+(ll)coins[j]<=amount) dp[i+(ll)coins[j]]=min(dp[i]+1LL,dp[i+(ll)coins[j]]);
            }
        }
        return dp[amount]!=INT_MAX?dp[amount]:-1;
    }
};
