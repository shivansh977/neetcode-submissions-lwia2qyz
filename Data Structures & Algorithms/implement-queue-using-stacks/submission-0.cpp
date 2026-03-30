class MyQueue {
private:
    stack<int> s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        stack<int> tmp;
        while(s.size()>1){
            tmp.push(s.top());
            s.pop();
        }
        int val=s.top();
        s.pop();
        while(!tmp.empty()){
            s.push(tmp.top());
            tmp.pop();
        }
        return val;
    }
    
    int peek() {
        stack<int> tmp;
        while(s.size()>1){
            tmp.push(s.top());
            s.pop();
        }
        int val=s.top();
        s.pop();
        tmp.push(val);
        while(!tmp.empty()){
            s.push(tmp.top());
            tmp.pop();
        }
        return val;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */