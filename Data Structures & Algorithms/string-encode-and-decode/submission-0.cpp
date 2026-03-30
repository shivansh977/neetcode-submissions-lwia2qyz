class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(int i=0;i<strs.size();i++){
            s=s+(to_string(strs[i].size())+"#"+strs[i]);
        } return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int id=0;
        while(id<s.size()){
            int len;string slen="";
            string tmp="";
            while(s[id]!='#'){
                slen.push_back(s[id]);
                id++;
            }id++;len=stoi(slen);
            for(int i=id;i<id+len;i++){
                tmp.push_back(s[i]);
            }id+=len;
            ans.push_back(tmp);
        }
        return ans;
    }
};
