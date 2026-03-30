class Solution {
private:
    void generate(vector<vector<int>>&fa, vector<int>& nums, int id, vector<int>&cur){
        if(id==nums.size()){
            fa.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!count(cur.begin(),cur.end(),i)){
                cur.push_back(i);
                generate(fa,nums,id+1,cur);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> fa;
        vector<int> cur;
        generate(fa,nums,0,cur);
        for(int i=0;i<fa.size();i++){
            for(int j=0;j<fa[i].size();j++){
                fa[i][j]=nums[fa[i][j]];
            }
        }
        return fa;
    }
};
