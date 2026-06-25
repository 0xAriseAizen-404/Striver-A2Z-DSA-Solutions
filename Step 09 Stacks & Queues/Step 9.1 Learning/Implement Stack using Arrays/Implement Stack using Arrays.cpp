// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

class myStack {
  private:
    int top = -1;
    int *arr;
    int sz;
  public:
    myStack(int n) {
        // Define Data Structures
        arr = new int[n];
        sz = n;
    }

    bool isEmpty() {
        // check if the stack is empty
        return top == -1;
    }

    bool isFull() {
        // check if the stack is full
        return top == sz - 1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if (isFull()) return;
        arr[++top] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if (isEmpty()) return;
        top -= 1;
    }

    int peek() {
        // Returns the top element of the stack
        return top == -1 ? -1 : arr[top];
    }
};