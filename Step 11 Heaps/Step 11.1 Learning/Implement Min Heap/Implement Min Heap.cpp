// https://www.geeksforgeeks.org/problems/min-heap-implementation/1

class Solution {
    public:
        vector<int> heap;
        void initializeHeap(){

        }

        void heapifyUp(int ind) {
            while (ind > 0 && heap[(ind - 1) / 2] > heap[ind]) {
                swap(heap[(ind - 1) / 2], heap[ind]);
                ind = (ind - 1) / 2;
            }
        }

        void heapifyDown(int ind) {
            int sz = heap.size();
            while (true) {
                int leftChild = 2 * ind + 1;
                int rightChild = 2 * ind + 2;
                int smallest = ind;
                if (leftChild < sz && heap[leftChild] < heap[smallest])
                    smallest = leftChild;
                if (rightChild < sz && heap[rightChild] < heap[smallest])
                    smallest = rightChild;
                if (ind == smallest) break;
                swap(heap[ind], heap[smallest]);
                ind = smallest;
            }
        }

        void insert(int key){
            heap.push_back(key);
            heapifyUp(heap.size() - 1);
        }

        void changeKey(int index, int new_val){
            int old_val = heap[index];
            heap[index] = new_val;
            if (new_val < old_val) heapifyUp(index);
            else heapifyDown(index);
        }

        void extractMin(){
            if (this->isEmpty()) return;
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        }

        bool isEmpty(){
            return heap.size() == 0;
        }

        int getMin(){
            return heap[0];
        }

        int heapSize(){
            return heap.size();
        }
};