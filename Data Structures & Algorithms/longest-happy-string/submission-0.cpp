class Solution {
private:
    bool notPresent(priority_queue<pair<int,int>> pq, char x){
        while(!pq.empty()){
            if(pq.top().second==int(x-'a')){
                return false;
            }
            pq.pop();
        }
        return true;
    }
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,int>> pq;
        vector<int> cnt(3,0);
        if(a) {pq.push({a,0});cnt[0]=a;}
        if(b) {pq.push({b,1});cnt[1]=b;}
        if(c) {pq.push({c,2});cnt[2]=c;}
        string ans="";
        while(!pq.empty()){
            auto x=pq.top();
            pq.pop();
            ans.push_back(char('a'+x.second));
            cnt[x.second]--;
            for(char ch='a';ch<='c';ch++){
                if((ans.size()<2||!(ans.back()==ans[ans.size()-2]&&ans.back()==ch))&&cnt[int(ch-'a')]&&notPresent(pq,ch)){
                    pq.push({cnt[int(ch-'a')],int(ch-'a')});
                }
            }
        }
        return ans;
    }
};