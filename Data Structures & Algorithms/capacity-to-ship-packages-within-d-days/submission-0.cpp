class Solution {
private:
    bool good(vector<int>& weights, int days, int maxWt){
        int cursum=0;
        int curdays=1;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>maxWt){
                return false;
            }
            if(cursum+weights[i]>maxWt){
                cursum=0;
                curdays++;
            }
            cursum+=weights[i];
        }
        return curdays<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0,r=1e9;
        while(l<r){
            int mid=l+(r-l)/2;
            bool isGood=good(weights,days,mid);
            if(isGood){
                r=mid;
            }
            else l=mid+1;
        }
        return l;
    }
};