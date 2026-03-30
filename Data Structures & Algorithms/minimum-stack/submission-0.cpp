class MinStack {
private:
    stack<pair<int,int>> s;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minval=INT_MAX;
        if(!s.empty()) minval=s.top().second;
        s.push({val,min(val,minval)});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
