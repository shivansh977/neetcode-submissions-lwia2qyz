class Solution {
private:
    bool ms(vector<int>& sticks, int totlen, int id, int s1, int s2, int s3, int s4){
        if(id==sticks.size()){
            if(s1==s2&&s3==s4&&s1==s3) return true;
            return false;
        }
        bool ans=false;
        if(4*(s1+sticks[id])<=totlen) ans=ans|ms(sticks,totlen,id+1,s1+sticks[id],s2,s3,s4);
        if(4*(s2+sticks[id])<=totlen) ans=ans|ms(sticks,totlen,id+1,s1,s2+sticks[id],s3,s4);
        if(4*(s3+sticks[id])<=totlen) ans=ans|ms(sticks,totlen,id+1,s1,s2,s3+sticks[id],s4);
        if(4*(s4+sticks[id])<=totlen) ans=ans|ms(sticks,totlen,id+1,s1,s2,s3,s4+sticks[id]);
        return ans;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int totlen=0;
        for(int i=0;i<matchsticks.size();i++){
            totlen+=matchsticks[i];
        }
        if(totlen%4) return false;
        return ms(matchsticks,totlen,0,0,0,0,0);
    }
};