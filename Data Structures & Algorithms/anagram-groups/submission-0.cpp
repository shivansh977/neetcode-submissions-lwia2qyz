class Solution {
private:
    string transform(string s){
        sort(s.begin(),s.end());
        return s;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        vector<vector<string>> soln;
        for(int i=0;i<strs.size();i++){
            m[transform(strs[i])].push_back(strs[i]);
        }
        for(auto it=m.begin();it!=m.end();it++){
            soln.push_back(it->second);
        }
        return soln;
    }
};
