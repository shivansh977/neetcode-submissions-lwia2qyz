class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        bool isNeg=n<0;
        n=max(n,-n);
        for(int i=0;i<n;i++){
            ans*=x;
        }
        if(isNeg) ans=1.0/ans;
        return ans;
    }
};
