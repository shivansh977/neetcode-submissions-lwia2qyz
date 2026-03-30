class Solution {
private:
    bool isEnough(int rate, vector<int>& piles, int h){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            time+=(long long)((long long)(piles[i]/rate)+bool(piles[i]%rate));
        }
        return time<=(long long)h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1e9;
        while(l<r){
            int mid=l+(r-l)/2;
            if(isEnough(mid,piles,h)){
                r=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};
