class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return false;
        multiset<int> s;
        for(int i=0;i<n;i++){
            s.insert(hand[i]);
        }
        int groups=n/groupSize;
        for(int i=0;i<groups;i++){
            int val=*s.begin();int gSize=1;
            s.erase(s.begin());
            while(gSize!=groupSize){
                auto it=s.lower_bound(val+1);
                if(it!=s.end()&&*it==val+1){
                    val++;s.erase(it);gSize++;
                }
                else{
                    return false;
                }
            }
        }
        return s.empty();
    }
};
