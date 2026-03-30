class Solution {
private:
    void generatePerm(vector<bool>& s, vector<vector<int>>& fa, vector<int>& cur){
        if(cur.size()==s.size()){
            fa.push_back(cur);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]){
                s[i]=false;
                cur.push_back(i);
                generatePerm(s,fa,cur);
                cur.pop_back();
                s[i]=true;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> s(int(nums.size()),true);
        vector<int> cur;
        vector<vector<int>> fa;
        generatePerm(s,fa,cur);
        set<vector<int>> filt;
        for(vector<int>& x:fa){
            for(int i=0;i<x.size();i++){
                x[i]=nums[x[i]];
            }
            filt.insert(x);
        }
        vector<vector<int>> ffa;
        for(const auto& v:filt) ffa.push_back(v);
        return ffa;
    }
};