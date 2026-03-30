class Solution {
private:
    bool recursiveSolve(vector<int>& piles, string& state, map<string,int>& dp, bool isAliceTurn){
        if(dp.count(state)) return dp[state];
        int n=state.length();
        int st=0,en=state.length()-1;
        for(int i=0;i<state.length();i++){
            if(state[i]=='.'){
                st=i;break;
            }
        }
        for(int i=state.length()-1;i>=0;i--){
            if(state[i]=='.'){
                en=i;break;
            }
        }
        if(st==en){
            state[st]='B';int aScore=0,bScore=0;
            for(int i=0;i<n;i++){
                if(state[i]=='A') aScore+=piles[i];
                else bScore+=piles[i];
            }
            return bScore<aScore;
        }
        char ch=isAliceTurn?'A':'B';
        state[st]=ch;
        bool ans1=recursiveSolve(piles,state,dp,!isAliceTurn);
        state[st]='.';
        state[en]=ch;
        bool ans2=recursiveSolve(piles,state,dp,!isAliceTurn);
        state[en]='.';
        if(ans1&&ans2) return dp[state]=false;
        return dp[state]=true;
    }
public:
    bool stoneGame(vector<int>& piles) {
        string state="";
        for(int i=0;i<piles.size();i++) state.push_back('.');
        map<string,int> dp;
        return recursiveSolve(piles, state, dp, true);
    }
};