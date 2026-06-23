// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
// https://www.geeksforgeeks.org/problems/k-sorted-array1610/1

// Approach ONE:
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void heapifyDown(vector<int> &heap, int ind) {
        int sz = heap.size();
        while (true) {
            int smallest = ind;
            int leftChild = 2 * ind + 1;
            int rightChild = 2 * ind + 2;
            if (leftChild < sz && heap[leftChild] < heap[smallest])
                smallest = leftChild;
            if (rightChild < sz && heap[rightChild] < heap[smallest])
                smallest = rightChild;
            if (smallest == ind) break;
            swap(heap[ind], heap[smallest]);
            ind = smallest;
        }
    }
    void buildMinHeap(vector<int> &heap) {
        int sz = heap.size();
        for (int i=sz/2-1; i>=0; --i)
            heapifyDown(heap, i);
    }
public:
    void sortNearlySortedArray(vector<int> &nums, int k) {
        vector<int> heap;
        for (int i=0; i<=k; ++i) {
            heap.push_back(nums[i]);
        }
        buildMinHeap(heap);
        int ind = 0;
        for (int i=k+1; i<nums.size(); ++i) {
            nums[ind++] = heap[0];
            
            heap[0] = nums[i];
            heapifyDown(heap, 0);
        }
        while (!heap.empty()) {
            nums[ind++] = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            if (!heap.empty()) heapifyDown(heap, 0);
        }
    }
};
int main() {
    Solution obj;
    vector<int> nums = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    obj.sortNearlySortedArray(nums, k);
    for (int &x: nums) cout << x << " ";
}

// Approach TWO;
class Solution {
public:
    void sortNearlySortedArray(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int ind = 0;
        for (int i = 0; i <= k; ++i)
            minHeap.push(nums[i]);
        for (int i = k + 1; i < nums.size(); ++i) {
            nums[ind++] = minHeap.top();
            minHeap.pop();
            minHeap.push(nums[i]);
        }
        while (!minHeap.empty()) {
            nums[ind++] = minHeap.top();
            minHeap.pop();
        }
    }
};

// TC: O(n logK)
// SC: O(K)

// if we use Standarad Sorting approach then
// TC: O(n logn)