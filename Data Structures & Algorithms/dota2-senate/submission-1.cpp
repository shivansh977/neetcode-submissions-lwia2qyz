class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        vector<bool> isThere(n,true);
        int i=0;
        bool flag=true;
        while(true){
            for(int k=i+1;k<i+1+n;k++){
                if(senate[k%n]!=senate[i%n]&&isThere[k%n]){
                    isThere[k%n]=false;
                    flag=false;
                    break;
                }
            }
            if(flag) break;
            flag=true;
            for(int k=i+1;k<i+1+n;k++){
                if(isThere[k%n]){
                    i=k;
                    flag=false;
                    break;
                }
            }
            if(flag) break;
            flag=true;
        }
        for(int i=0;i<senate.size();i++){
            if(isThere[i]&&senate[i]=='R'){
                return "Radiant";
            }
        }
        return "Dire";
    }
};