// https://www.geeksforgeeks.org/problems/implement-queue-using-array/1

class myQueue {
  private:
    int front, rear;
    int sz;
    int *arr;
  public:
    myQueue(int n) {
        // Define Data Structures
        arr = new int[n];
        front = -1;
        rear = -1;
        sz = n;
    }

    bool isEmpty() {
        // check if the queue is empty
        return front == -1;
    }

    bool isFull() {
        // check if the queue is full
        return (rear + 1) % sz == front;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if (isFull()) return;
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % sz;
        arr[rear] = x;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if (isEmpty()) return;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % sz;
    }

    int getFront() {
        // Returns the front element of the queue.
        return isEmpty() ? -1 : arr[front];
    }

    int getRear() {
        // Return the last element of queue
        return isEmpty() ? -1 : arr[rear];
    }
};