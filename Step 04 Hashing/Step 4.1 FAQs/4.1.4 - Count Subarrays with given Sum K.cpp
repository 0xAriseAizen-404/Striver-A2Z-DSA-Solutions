class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = 1;
        int pre_sum = 0;
        int ans = 0;
        for (const auto &x: nums) {
            pre_sum += x;
            if (umap.find(pre_sum - k) != umap.end()) ans += umap[pre_sum - k];
            umap[pre_sum] += 1;
        }
        return ans;
    }
};