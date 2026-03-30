class Solution {
private:
    int oper(int n){
        int ans=0;
        while(n>0){
            int x=n%10;
            ans+=(x*x);
            n/=10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        map<int,bool> m;
        while(!m[n]){
            m[n]=true;
            n=oper(n);
        }
        if(n==1) return true;
        return false;
    }
};
