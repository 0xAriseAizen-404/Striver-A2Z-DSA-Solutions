// https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1

class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
  private:
    Node *front, *rear;
    int sz;
  public:
    myQueue() {
        // Initialize your data members
        front = NULL;
        rear = NULL;
        sz = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front == NULL;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        if (rear == NULL) rear = front = new Node(x);
        else {
            rear->next = new Node(x);
            rear = rear->next;
        }
        sz++;
    }

    void dequeue() {
        // Removes the front element of the queue
        if (isEmpty()) return;
        Node *temp = front;
        front = front->next;
        delete temp;
        if (front == NULL) rear = NULL;
        sz--;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        return isEmpty() ? -1 : front->data;
    }

    int size() {
        // Returns the current size of the queue.
        return sz;
    }
};
