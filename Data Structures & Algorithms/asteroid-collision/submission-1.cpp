class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> fa;
        fa.push_back(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            if(asteroids[i]<0){
                while(!fa.empty()&&fa.back()>0&&fa.back()<-asteroids[i]){
                    fa.pop_back();
                }
            }
            if(fa.back()==-asteroids[i]&&asteroids[i]<0){
                fa.pop_back();continue;
            }
            if(fa.empty()||(fa.back()<0&&asteroids[i]<0)||(asteroids[i]>0)){
                fa.push_back(asteroids[i]);
            }
        }
        return fa;
    }
};