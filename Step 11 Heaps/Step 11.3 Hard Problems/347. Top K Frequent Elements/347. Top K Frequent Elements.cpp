// My Own Fucking Code: Without looking at the previous submissions
// Improvised through 0ms solution candidate
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        using pii = pair<int, int>;
        for (int &x: nums) ++umap[x];

        priority_queue<pii, vector<pii>,  greater<pii>> minHeap;
        for (auto &[num, cnt]: umap) {
            minHeap.push({cnt, num});
            if (minHeap.size() > k) minHeap.pop();
        }
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};