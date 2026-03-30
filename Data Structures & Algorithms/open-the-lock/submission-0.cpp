class Solution {
private:
    bool hasString(vector<string>& strings, string& s){
        for(int i=0;i<strings.size();i++){
            if(s==strings[i]) return true;
        }
        return false;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        map<string,int> dist;
        map<string,bool> vis;
        queue<string> q;
        q.push("0000");
        dist["0000"]=0;
        vis["0000"]=true;
        while(!q.empty()){
            string x=q.front();
            string x1=x;
            string x2=x;
            q.pop();
            if(hasString(deadends,x)) continue;
            if(x==target) break;
            for(int i=0;i<4;i++){
                if(x1[i]=='9') x1[i]='0';
                else x1[i]++;
                if(x2[i]=='0') x2[i]='9';
                else x2[i]--;
                if(!vis[x1]){
                    vis[x1]=true;
                    dist[x1]=dist[x]+1;
                    q.push(x1);
                }
                if(!vis[x2]){
                    vis[x2]=true;
                    dist[x2]=dist[x]+1;
                    q.push(x2);
                }
                if(x2[i]=='9') x2[i]='0';
                else x2[i]++;
                if(x1[i]=='0') x1[i]='9';
                else x1[i]--;
            }
        }
        cout<<dist["0000"];
        return dist.count(target)?dist[target]:-1;
    }
};