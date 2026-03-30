class Solution {
public:
    int reverse(int x) {
        bool isNeg=x<0;
        int ans=0;
        if(isNeg) x=-x;
        while(x>0){
            if(ans>INT_MAX/10) return 0;
            ans*=10;
            int dig=x%10;
            x/=10;
            ans+=dig;
        }
        if(isNeg) ans=-ans;
        return ans;
    }
};
