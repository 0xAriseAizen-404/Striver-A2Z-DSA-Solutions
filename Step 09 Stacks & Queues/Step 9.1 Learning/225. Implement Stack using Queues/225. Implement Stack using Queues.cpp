class MyStack {
public:
    queue<int> queue_1;
    queue<int> queue_2;
    MyStack() { }
    
    void push(int x) {
        while (!queue_1.empty()) {
            queue_2.push(queue_1.front());
            queue_1.pop();
        }
        queue_1.push(x);
        while (!queue_2.empty()) {
            queue_1.push(queue_2.front());
            queue_2.pop();
        }
    }
    
    int pop() {
        if (queue_1.empty()) return -1;
        int val = queue_1.front();
        queue_1.pop();
        return val;
    }
    
    int top() {
        return queue_1.front();
    }
    
    bool empty() {
        return queue_1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */