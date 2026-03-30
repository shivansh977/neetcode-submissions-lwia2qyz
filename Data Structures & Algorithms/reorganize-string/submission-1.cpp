class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        vector<int> cnt(26,0);
        for(int i=0;i<s.length();i++){
            cnt[int(s[i]-'a')]++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]) pq.push({cnt[i],char('a'+i)});
        }
        string ans="";
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            if(!ans.empty()&&cnt[int(ans.back()-'a')]){
                pq.push({cnt[int(ans.back()-'a')],ans.back()});
            }
            ans.push_back(x.second);
            cnt[int(x.second-'a')]--;
        }
        if(ans.length()!=s.length()) return "";
        return ans;
    }
};