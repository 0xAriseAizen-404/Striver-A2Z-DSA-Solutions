class MyQueue {
public:
    stack<int> stack_1;
    stack<int> stack_2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!stack_1.empty()) {
            stack_2.push(stack_1.top());
            stack_1.pop();
        }
        stack_1.push(x);
        while (!stack_2.empty()) {
            stack_1.push(stack_2.top());
            stack_2.pop();
        }
    }
    
    int pop() {
        if (stack_1.empty()) return -1;
        int val = stack_1.top();
        stack_1.pop();
        return val;
    }
    
    int peek() {
        return stack_1.top();
    }
    
    bool empty() {
        return stack_1.empty();
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