// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1

class Solution {
  private:
    struct cmp {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
            return a.first < b.first;
        }
    };
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int sz = b.size();
        for (int i=0; i<a.size(); ++i) pq.push({a[i]+b[sz-1], sz-1});
        vector<int> res;
        while (!pq.empty() && k--) {
            auto pair = pq.top(); pq.pop();
            res.push_back(pair.first);
            int ind = pair.second;
            if (ind - 1 >= 0)
                pq.push({pair.first - b[ind] + b[ind - 1], ind - 1});
        }
        return res;
    }
};