class LFUCache {
private:
    multiset<int> s;                  // stores frequencies
    map<int,int> nodeFreq;            // key -> freq
    map<int,int> cacheData;           // key -> value
    map<int,queue<int>> cacheMap;     // freq -> keys
    int capacity;
    int size;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
    }
    
    int get(int key) {
        if(!cacheData.count(key)) return -1;

        int val = cacheData[key];
        int oldFreq = nodeFreq[key];
        int newFreq = oldFreq + 1;

        // remove one occurrence of oldFreq
        auto it = s.find(oldFreq);
        if(it != s.end()) s.erase(it);

        nodeFreq[key] = newFreq;
        cacheMap[newFreq].push(key);
        s.insert(newFreq);

        return val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        // If key already exists → update only
        if(cacheData.count(key)) {
            cacheData[key] = value;
            get(key);   // reuse freq update logic
            return;
        }

        // Eviction
        if(size == capacity) {
            int freq = *s.begin();
            s.erase(s.begin());

            queue<int>& q = cacheMap[freq];

            while(!q.empty() && nodeFreq[q.front()] != freq) {
                q.pop();
            }

            int evictKey = -1;
            if(!q.empty()) {
                evictKey = q.front();
                q.pop();
            }

            if(q.empty()) cacheMap.erase(freq);

            nodeFreq.erase(evictKey);
            cacheData.erase(evictKey);
            size--;
        }

        // Insert new key
        nodeFreq[key] = 1;
        cacheData[key] = value;
        cacheMap[1].push(key);
        s.insert(1);
        size++;
    }
};