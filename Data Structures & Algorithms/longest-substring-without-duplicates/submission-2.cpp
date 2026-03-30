class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastAppear(128,-1);
        int id_start=0;
        int maxa=0;
        for(int i=0;i<s.length();i++){
            if(lastAppear[int(s[i])]!=-1){
                id_start=max(lastAppear[int(s[i])]+1,id_start);
            }
            lastAppear[int(s[i])]=i;
            maxa=max(maxa,i-id_start+1);
        }
        return maxa;
    }
};
