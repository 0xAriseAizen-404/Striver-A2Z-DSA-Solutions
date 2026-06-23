// https://www.naukri.com/code360/problems/convert-min-heap-to-max-heap_1381084

class Solution {
private:
    void heapifyDown(vector<int> &heap, int ind) {
        int sz = heap.size();
        while (true) {
            int leftChild = 2 * ind + 1;
            int rightChild = 2 * ind + 2;
            int largest = ind;

            if (leftChild < sz && heap[largest] < heap[leftChild])
                largest = leftChild;
            if (rightChild < sz && heap[largest] < heap[rightChild])
                largest = rightChild;
            
            if (largest == ind) break;
            swap(heap[ind], heap[largest]);
            ind = largest;
        }
    }
public:
    vector<int> minToMaxHeap(vector<int> nums) {
        int sz = nums.size();
        for (int ind = sz/2 - 1; ind >= 0; ind--) {
            heapifyDown(nums, ind);
        }
        return nums;
    }
};