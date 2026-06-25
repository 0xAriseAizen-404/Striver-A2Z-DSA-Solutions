// // 0ms Approach:
// class MinStack {
// private:
//     stack<pair<int, int>> st;
// public:
//     MinStack() {
        
//     }
    
//     void push(int value) {
//         if (!st.empty()) st.push({value, min(value, st.top().second)});
//         else st.push({value, value});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };
// TC: O(1) for push, pop, top, getMin
// SC: O(2n)

// My Approach: 
class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (min_st.empty() || val <= min_st.top()) min_st.push(val);
    }
    
    void pop() {
        if (st.top() == min_st.top()) min_st.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
// TC: O(1) for push, pop, top, getMin
// SC: O(n + k), k is small elements which are less or equal at a time

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */