class DSU{
private:
    vector<int> rank;
    vector<int> parent;
public:
    DSU(int n){
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int n){
        if(n!=parent[n]){
            return parent[n]=find(parent[n]);
        }
        return n;
    }
    void unionAll(int n, int m){
        int nrep=find(n);
        int mrep=find(m);
        if(nrep==mrep) return;
        if(rank[nrep]>rank[mrep]){
            parent[mrep]=nrep;
        }
        else if(rank[nrep]<rank[mrep]){
            parent[nrep]=mrep;
        }
        else{
            parent[mrep]=nrep;
            rank[nrep]++;
        }
    }
};

class Sieve{
private:
    vector<bool> isPrime;
    vector<int> primes;
public:
    Sieve(int n){
        isPrime.resize(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        for(int i=2;i<=n;i++){
            if(isPrime[i]){
                for(int k=2;k*i<=n;k++){
                    isPrime[k*i]=false;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(isPrime[i]) primes.push_back(i);
        }
    }
    vector<int>& getSieve(){
        return this->primes;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int maxval=0;
        DSU dsu(int(nums.size()));
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++) {
            maxval=max(maxval,nums[i]);
            mp[nums[i]].push_back(i);
        }
        Sieve sieve(maxval);
        for(int prime:sieve.getSieve()){
            vector<int> temp;
            for(int k=1;k*prime<=maxval;k++){
                for(int tval:mp[k*prime]) temp.push_back(tval);
            }
            for(int i=1;i<temp.size();i++){
                dsu.unionAll(temp[0],temp[i]);
            }
        }
        int val=dsu.find(0);
        for(int i=0;i<nums.size();i++){
            if(val!=dsu.find(i)) return false;
        }
        return true;
    }
};