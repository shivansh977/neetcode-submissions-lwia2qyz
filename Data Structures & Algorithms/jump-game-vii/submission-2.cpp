class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[0]=='1'||s.back()=='1') return false;
        int id=0;int n=s.size();
        while(true){
            int pid=id;
            for(int i=min(id+maxJump,n-1);i>=id+minJump;i--){
                if(s[i]=='0'&&(n-1-i>=minJump||i==n-1)){
                    id=i;break;
                }
            }
            if(pid==id) break;
        }
        return id==n-1;
    }
};