class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> tmp;
        while(q.size()>1){
            tmp.push(q.front());
            q.pop();
        }
        int ans=q.front();
        q.pop();
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        return ans;
    }
    
    int top() {
        queue<int> tmp;
        while(q.size()>1){
            tmp.push(q.front());
            q.pop();
        }
        int ans=q.front();
        tmp.push(ans);
        q.pop();
        while(!tmp.empty()){
            q.push(tmp.front());
            tmp.pop();
        }
        return ans;
    }
    
    bool empty() {
        return q.empty();
    }
};
//0 1 2 3

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */