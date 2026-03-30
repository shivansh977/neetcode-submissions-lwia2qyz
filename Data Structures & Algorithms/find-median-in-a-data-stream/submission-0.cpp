class MedianFinder {
private:
    priority_queue<int> pq1;
    priority_queue<int,vector<int>,greater<int>> pq2;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(pq1.empty()) {pq1.push(num);return;}
        if(pq1.size()==pq2.size()){
            if(pq2.empty()||num<=pq2.top()){
                pq1.push(num);
            }
            else{
                pq1.push(pq2.top());
                pq2.pop();
                pq2.push(num);
            }
        }
        else{
            if(num>=pq1.top()){
                pq2.push(num);
            }
            else{
                pq2.push(pq1.top());
                pq1.pop();
                pq1.push(num);
            }
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size()){
            return (1.0)*(double)(pq1.top()+pq2.top())/2.0;
        }
        else{
            return (double)pq1.top();
        }
    }
};
