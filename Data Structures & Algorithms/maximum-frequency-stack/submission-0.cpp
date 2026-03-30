class FreqStack {
private:
    multiset<int> ms;
    map<int,int> cnt;
    map<int,vector<int>> addedAt;
    map<int,set<pair<int,int>>> cnti;
    int pushId;
public:
    FreqStack() {
        pushId=0;
    }
    
    void push(int val) {
        if(!cnt.count(val)){
            ms.insert(1);
            cnt[val]++;
            addedAt[val].push_back(pushId++);
            cnti[1].insert({addedAt[val].back(),val});
        }
        else{
            int curFreq=cnt[val];
            int curAddedAt=addedAt[val].back();
            int newAddedAt=pushId++;
            addedAt[val].push_back(newAddedAt);
            cnt[val]++;
            ms.erase(ms.lower_bound(curFreq));
            ms.insert(curFreq+1);
            cnti[curFreq].erase(cnti[curFreq].find({curAddedAt,val}));
            cnti[curFreq+1].insert({newAddedAt,val});
        }
    }
    
    int pop() {
        auto it=ms.rbegin();
        int freq=*it;
        ms.erase(ms.lower_bound(freq));
        pair<int,int> x=*cnti[freq].rbegin();
        cnti[freq].erase(cnti[freq].find(x));
        int val=x.second;
        addedAt[val].pop_back();
        if(freq==1){
            cnt.erase(val);
        }
        else{
            ms.insert(freq-1);
            cnt[val]--;
            cnti[freq-1].insert({addedAt[val].back(),val});
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */