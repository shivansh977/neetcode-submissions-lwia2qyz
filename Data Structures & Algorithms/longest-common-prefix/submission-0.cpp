class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int id=0;
        while(true){
            bool flag=false;
            for(int i=0;i<strs.size();i++){
                if(id>=min(strs[0].size(),strs[i].size())||strs[i][id]!=strs[0][id]){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
            id++;
        }
        return strs[0].substr(0,id);
    }
};