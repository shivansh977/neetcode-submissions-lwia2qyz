class Solution {
private:
    void routine(string& s, vector<vector<bool>>& isPallin, int i, int j){
        isPallin[i][j]=true;
        while(i>0&&j+1<s.length()&&s[i-1]==s[j+1]){
            i--;j++;
            isPallin[i][j]=true;
        }
    }
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>> isPallin(n,vector<bool>(n,false));
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            routine(s,isPallin,i,i);
            if(i<n-1&&s[i]==s[i+1]) routine(s,isPallin,i,i+1);
        }
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=0;j<=i;j++){
                if(isPallin[j][i]) ans++;
            }
            if(i>0) ans+=dp[i-1];
            dp[i]=ans;
        }
        return dp.back();
    }
};
