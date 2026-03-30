class Solution {
private:
    bool hasString(vector<string>& wordDict, string s){
        for(int i=0;i<wordDict.size();i++){
            if(wordDict[i]==s) return true;
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&hasString(wordDict,s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
