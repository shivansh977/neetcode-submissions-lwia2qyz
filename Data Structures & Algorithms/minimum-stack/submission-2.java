class MinStack {

    Deque<List<Integer>> dq;

    public MinStack() {
        dq = new ArrayDeque();
    }
    
    public void push(int val) {
        if(dq.isEmpty()){
            dq.push(List.of(val,val));
            return;
        }
        List<Integer> topElement = dq.peek();
        dq.push(List.of(val,Math.min(topElement.get(1),val)));
    }
    
    public void pop() {
        dq.pop();
    }
    
    public int top() {
        return dq.peek().get(0);
    }
    
    public int getMin() {
        return dq.peek().get(1);
    }
}
