// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class myStack {
  private:
    Node *head;
    int sz;

  public:
    myStack() {
        // Initialize your data members
        head = nullptr;
        sz = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return sz == 0;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node *element = new Node(x);
        element->next = head;
        head = element;
        sz++;
    }

    void pop() {
        // Removes the top element of the stack
        if (!head) return;
        head = head->next;
        sz--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        return !head ? -1 : head->data;
    }

    int size() {
        // Returns the current size of the stack.
        return sz;
    }
};