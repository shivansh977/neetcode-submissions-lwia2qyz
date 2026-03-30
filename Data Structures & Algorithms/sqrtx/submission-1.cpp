class Solution {
public:
    int mySqrt(int x) {
        long long l=0,r=pow(2,16);
        while(l<r){
            long long mid=l+(r-l)/2;
            if(mid*mid>=x){
                r=mid;
            }
            else l=mid+1;
        }
        if(l*l!=x) l--;
        return l;
    }
};