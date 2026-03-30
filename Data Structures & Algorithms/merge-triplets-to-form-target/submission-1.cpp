class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> triplet = {0,0,0};
        vector<int> nc;
        for(int i=0;i<triplets.size();i++){
            for(int j=0;j<3;j++){
                if(triplets[i][j]>target[j]){
                    nc.push_back(i);
                    break;
                }
            }
        }
        for(int i=triplets.size()-1;i>=0;i--){
            if(!nc.empty()&&nc.back()==i){
                nc.pop_back();
                continue;
            }
            for(int j=0;j<3;j++){
                triplet[j]=max(triplet[j],triplets[i][j]);
            }
        }
        for(int j=0;j<3;j++){
            if(triplet[j]!=target[j]) return false;
        }
        return true;
    }
};
