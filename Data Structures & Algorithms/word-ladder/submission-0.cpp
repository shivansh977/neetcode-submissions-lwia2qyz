class Solution {
private:
    bool distone(string& s1, string& s2){
        int dist=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) dist++;
        }
        return dist==1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int target=-1;
        int n=wordList.size();
        vector<vector<int>> adj(n);
        vector<int> dist(n,INT_MAX);
        queue<int> q;
        for(int i=0;i<wordList.size();i++){
            if(endWord==wordList[i]) target=i;
            for(int j=i+1;j<wordList.size();j++){
                if(distone(wordList[i],wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
            if(distone(wordList[i],beginWord)) {q.push(i);dist[i]=1;}
        }
        if(target==-1) return 0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==target){
                break;
            }
            for(int neigh:adj[node]){
                if(dist[neigh]==INT_MAX){
                    q.push(neigh);
                }
                dist[neigh]=min(dist[neigh],dist[node]+1);
            }
        }
        if(dist[target]==INT_MAX) return 0;
        return dist[target]+1;
    }
};
