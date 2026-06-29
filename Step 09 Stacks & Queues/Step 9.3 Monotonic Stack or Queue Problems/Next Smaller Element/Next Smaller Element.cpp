// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

class Solution {
  public:
    vector<int> nextSmallerEle(vector<int> &arr) {
        //  code here
        int sz = arr.size();
        vector<int> ans(sz, -1);
        stack<int> mis; // Monotonic Increasing Stack
        for (int i=sz-1; i>=0; --i) {
            int val = arr[i];
            while (!mis.empty() && val<=mis.top()) mis.pop();
            if (!mis.empty()) ans[i] = mis.top();
            mis.push(val);
        }
        return ans;
    }
};