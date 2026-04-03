class MyCircularQueue {
private:
    vector<int> q;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        front=0;rear=-1;q.resize(k,-1);
    }
    
    bool enQueue(int value) {
        int n=q.size();
        if(rear!=-1&&(rear+1)%n==front){
            return false;
        }
        rear=(rear+1)%n;
        q[rear]=value;
        return true;
    }
    
    bool deQueue() {
        int n=q.size();
        if(isEmpty()) return false;
        if(front==rear){
            q[front]=-1;
            front=0;
            rear=-1;
            return true;
        }
        q[front]=-1;
        front=(front+1)%n;
        return true;
    }
    
    int Front() {
        return q[front];
    }
    
    int Rear() {
        return rear==-1?-1:q[rear];
    }
    
    bool isEmpty() {
        return rear==-1;
    }
    
    bool isFull() {
        int n=q.size();
        return rear!=-1&&(rear+1)%n==front;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */