// https://www.geeksforgeeks.org/problems/kth-largest-element5034/1

// Approach ONE:
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthLargestElement(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int &x: nums) {
            minHeap.push(x);
            if (minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
    }
};
int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << obj.kthLargestElement(nums, 2);
}

// Approach TWO:
class Solution {
private:
    void heapifyDown(vector<int> &heap, int ind) {
        int n = heap.size();

        while (true) {
            int l = 2 * ind + 1;
            int r = 2 * ind + 2;
            int smallest = ind;

            if (l < n && heap[l] < heap[smallest])
                smallest = l;

            if (r < n && heap[r] < heap[smallest])
                smallest = r;

            if (smallest == ind) break;

            swap(heap[ind], heap[smallest]);
            ind = smallest;
        }
    }

    void buildMinHeap(vector<int> &heap) {
        int n = heap.size();

        for (int i = n / 2 - 1; i >= 0; --i)
            heapifyDown(heap, i);
    }

public:
    int kthLargestElement(vector<int>& nums, int k) {
        vector<int> heap;

        for (int i = 0; i < k; ++i)
            heap.push_back(nums[i]);

        buildMinHeap(heap);

        for (int i = k; i < nums.size(); ++i) {
            if (heap[0] < nums[i]) {
                heap[0] = nums[i];
                heapifyDown(heap, 0);
            }
        }

        return heap[0];
    }
};