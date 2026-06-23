class KthLargest {
private:
    vector<int> min_heap;
    int k;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            // Add new element at the end of vector
            min_heap.push_back(num);
            //  push_heap();
             // Assumes [begin, end-1) is already a heap. Takes the LAST element (just inserted) and moves i  until heap property is restored.
            // Since we're using greater<int>(),  this becomes a MIN HEAP.
            // Example: [5, 8] push_back(3) => [5, 8, 3]
            // push_heap(...) => [3, 8, 5]
            push_heap(min_heap.begin(), min_heap.end(), greater<int>());
            if (min_heap.size() > k) {
                // pop_heap():
                // DOES NOT REMOVE the element. It moves the heap's TOP element (smallest element for min-heap) to the END of the vector.
                // Example: [3, 5, 8] pop_heap(...) [5, 8, 3]
                pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
                // Actually remove the element
                min_heap.pop_back();
            }
        }
    }

    int add(int val) {
        min_heap.push_back(val);
        // Restore heap property
        push_heap(min_heap.begin(), min_heap.end(), greater<int>());
        // If heap grows larger than k, remove smallest element
        if (min_heap.size() > k) {
            // Move smallest element to end
            pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
            // Remove it
            min_heap.pop_back();
        }
        return min_heap.front();
    }
};