class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> passengers(1001,0);
        for(int i=0;i<trips.size();i++){
            for(int j=trips[i][1];j<trips[i][2];j++){
                passengers[j]+=trips[i][0];
            }
        }
        for(int i=0;i<=1000;i++){
            if(passengers[i]>capacity) return false;
        }
        return true;
    }
};