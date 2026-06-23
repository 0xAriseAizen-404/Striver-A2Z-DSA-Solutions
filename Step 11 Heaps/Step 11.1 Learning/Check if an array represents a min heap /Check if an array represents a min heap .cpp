// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMinHeap(vector<int> &heap) {
        int sz = heap.size();
        for (int ind = 0; ind <= (sz - 1) / 2; ++ind) {
            int leftChild = 2 * ind + 1;
            if (leftChild < sz && heap[ind] > heap[leftChild]) return false;

            int rightChild = 2 * ind + 2;
            if (rightChild < sz && heap[ind] > heap[rightChild]) return false;
        }
        return true;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {10, 20, 30, 21, 23};

    cout << (obj.isMinHeap(nums) ? "true" : "false") << endl;
    return 0;
}