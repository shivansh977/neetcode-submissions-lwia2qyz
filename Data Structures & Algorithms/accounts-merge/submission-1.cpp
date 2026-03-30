class DSU{
private:
    vector<int> rank;
    vector<int> parent;
public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x){
            return parent[x]=find(parent[x]);
        }
        return x;
    }

    void unionAll(int a, int b){
        int arep=find(a);
        int brep=find(b);
        if(arep==brep) return;
        if(rank[arep]>rank[brep]){
            parent[brep]=arep;
        }
        else if(rank[brep]>rank[arep]){
            parent[arep]=brep;
        }
        else{
            parent[brep]=arep;
            rank[arep]++;
        }
    }

};

class Solution {
private:
    vector<string> merge(vector<string>& a, vector<string>& b){
        set<string> accts;
        vector<string> ans={a[0]};
        for(int i=1;i<a.size();i++) accts.insert(a[i]);
        for(int i=1;i<b.size();i++) accts.insert(b[i]);
        for(auto const& s:accts){
            ans.push_back(s);
        }
        return ans;
    }
    vector<string> normalise(vector<string>& a){
        set<string> accts;
        vector<string> fa={a[0]};
        for(int i=1;i<a.size();i++){
            accts.insert(a[i]);
        }
        for(auto const& s:accts){
            fa.push_back(s);
        }
        return fa;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        map<string,vector<int>> mp;
        map<int,vector<string>> sol;
        DSU dsu(n);
        for(int i=0;i<accounts.size();i++){
            accounts[i]=normalise(accounts[i]);
            for(int j=1;j<accounts[i].size();j++){
                mp[accounts[i][j]].push_back(i);
            }
        }
        for(auto const& p:mp){
            const vector<int>& v=p.second;
            for(int i=1;i<v.size();i++){
                //cout<<v[0]<<" "<<v[i]<<"\n";
                dsu.unionAll(v[0],v[i]);
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dsu.find(i)<<"\n";
        // }
        for(int i=0;i<n;i++){
            if(!sol.count(dsu.find(i))){
                sol[dsu.find(i)]=accounts[i];
            }
            else{
                sol[dsu.find(i)]=merge(sol[dsu.find(i)],accounts[i]);
            }
        }
        vector<vector<string>> fa;
        for(auto const& aa:sol){
            fa.push_back(aa.second);
        }
        return fa;
    }
};