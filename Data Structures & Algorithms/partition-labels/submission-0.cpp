class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastApp(26,-1);
        for(int i=0;i<s.length();i++){
            lastApp[int(s[i]-'a')]=i;
        }
        vector<int> fa;
        int st=0;
        while(st<s.length()){
            int curval=st;
            int en=lastApp[int(s[st]-'a')];
            while(st<en){
                st++;
                en=max(en,lastApp[int(s[st]-'a')]);
            }
            fa.push_back(en-curval+1);
            st++;
        }
        return fa;
    }
};
