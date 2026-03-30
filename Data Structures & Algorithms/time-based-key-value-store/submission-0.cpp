class TimeMap {
private:
    map<string,string> vals;
    map<string, vector<int>> ts;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ts[key].push_back(timestamp);
        vals[key+"_"+to_string(timestamp)]=value;
    }
    
    string get(string key, int timestamp) {
        int id=upper_bound(ts[key].begin(),ts[key].end(),timestamp)-ts[key].begin();
        if(id==0) return "";
        int x=ts[key][id-1];
        return vals[key+"_"+to_string(x)];
    }
};
