// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

// Approach ONE:
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int KthSmallestElement(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        for (int &x: nums) {
            maxHeap.push(x);
            if (maxHeap.size() > k) maxHeap.pop();
        }
        return maxHeap.top();
    }
};
int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << obj.KthSmallestElement(nums, 2);
}

// Approach TWO:
class Solution {
private:
    void heapifyDown(vector<int> &heap, int ind) {
        int n = heap.size();

        while (true) {
            int l = 2 * ind + 1;
            int r = 2 * ind + 2;
            int largest = ind;

            if (l < n && heap[l] > heap[largest])
                largest = l;

            if (r < n && heap[r] > heap[largest])
                largest = r;

            if (largest == ind) break;

            swap(heap[ind], heap[largest]);
            ind = largest ;
        }
    }

    void buildMaxHeap(vector<int> &heap) {
        int n = heap.size();

        for (int i = n / 2 - 1; i >= 0; --i)
            heapifyDown(heap, i);
    }

public:
    int KthSmallestElement(vector<int>& nums, int k) {
        vector<int> heap;

        for (int i = 0; i < k; ++i)
            heap.push_back(nums[i]);

        buildMaxHeap(heap);

        for (int i = k; i < nums.size(); ++i) {
            if (heap[0] > nums[i]) {
                heap[0] = nums[i];
                heapifyDown(heap, 0);
            }
        }

        return heap[0];
    }
};