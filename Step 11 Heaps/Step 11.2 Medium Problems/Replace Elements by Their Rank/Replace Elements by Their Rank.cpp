// https://www.geeksforgeeks.org/problems/convert-an-array-to-reduced-form1101/1

// GFG Problem Solution
// My OWN Solution
class Solution {
  public:
    void replaceWithRank(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int &x: arr) pq.push(x);
        
        int rank = 0;
        unordered_map<int, pair<int, int>> umap;
        while (!pq.empty()) {
            int x = pq.top(); pq.pop();
            if (umap.find(x) != umap.end()) umap[x].second += 1;
            else umap[x] = {rank, 1};
            rank++;
        }
        for (int i=0; i<arr.size(); ++i) {
            int x = umap[arr[i]].second;
            rank = umap[arr[i]].first;
            if (x == 1) umap.erase(arr[i]);
            else {
                umap[arr[i]].first += 1;
                umap[arr[i]].second -= 1;
            }
            arr[i] = rank;
        }
    }
};

// Striver Problem Solution
// My OWN Solution
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> replaceWithRank(vector<int> &arr) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int &x: arr) minHeap.push(x);
        
        int sz = 1;
        unordered_map<int, int> umap;
        while (!minHeap.empty()) {
            int x = minHeap.top();
            if (umap.find(x) == umap.end()) umap[x] = sz++;
            minHeap.pop();
        }
        for (int i=0; i<arr.size(); ++i) arr[i] = umap[arr[i]];
        return arr;
    }
};
int main() {
    Solution obj;
    vector<int> arr = {1, 5, 8, 15, 8, 25, 9};
    arr = obj.replaceWithRank(arr);
    for (int &x: arr) cout << x << " ";
    return 0;
}