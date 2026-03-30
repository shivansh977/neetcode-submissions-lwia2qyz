class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,int>> car;
        for(int i=0;i<n;i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end());
        int ans=0;
        while(!car.empty()){
            ans++;
            pair<int,int> car_b = car.back();
            car.pop_back();
            while(!car.empty()&&(target-car.back().first)*car_b.second<=(target-car_b.first)*car.back().second){
                car.pop_back();
            }
        }
        return ans;
    }
};
