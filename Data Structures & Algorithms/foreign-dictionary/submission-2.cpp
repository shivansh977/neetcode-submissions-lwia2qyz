class Solution {
private:
    pair<int,int> find(string a, string b){
        int n=a.length();
        int m=b.length();
        if(m>n&&a==b.substr(0,n)){
            return {-1,-1};
        }
        else if(n>m&&a.substr(0,m)==b){
            return {-2,-2};
        }
        for(int i=0;i<min(n,m);i++){
            if(a[i]!=b[i]){
                return {int(a[i]-'a'),int(b[i]-'a')};
            }
        }
        return {-1,-1};
    }
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<int> inDegree(26,-1);
        vector<bool> isThere(26,false);
        vector<bool> vis(26,false);
        for(int i=0;i<words.size();i++){
            if(i>0){
                pair<int,int> x=find(words[i-1],words[i]);
                if(x.first==-1) continue;
                if(x.first==-2) return "";
                adj[x.first].push_back(x.second);
                if(inDegree[x.second]==-1) inDegree[x.second]++;
                inDegree[x.second]++;
            }
            for(int j=0;j<words[i].length();j++) isThere[int(words[i][j]-'a')]=true;
        }
        queue<int> q;
        for(int i=0;i<26;i++){
            if(inDegree[i]==-1&&isThere[i]){
                inDegree[i]=0;
                q.push(i);
            }
        }
        string fa="";
        while(!q.empty()){
            int x=q.front();
            q.pop();
            vis[x]=true;
            fa.push_back(char('a'+x));
            for(int v:adj[x]){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }
            }
        }
        for(int i=0;i<26;i++){
            if(isThere[i]&&!vis[i]) return "";
        }
        return fa;
    }
};
