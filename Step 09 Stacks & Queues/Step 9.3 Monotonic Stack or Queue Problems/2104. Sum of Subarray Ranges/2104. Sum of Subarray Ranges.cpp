class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int sz = nums.size();
        vector<int> nse(sz, sz), nge(sz, sz);
        vector<int> pse(sz, -1), pge(sz, -1);
        stack<int> mis;
        stack<int> mds;

        // nse + nge
        for (int i=sz-1; i>=0; --i) {
            while (!mis.empty() && nums[mis.top()] >= nums[i]) mis.pop();
            nse[i] = mis.empty() ? sz : mis.top();
            mis.push(i);

            while (!mds.empty() && nums[mds.top()] <= nums[i]) mds.pop();
            nge[i] = mds.empty() ? sz : mds.top();
            mds.push(i);
        }

        while (!mis.empty()) mis.pop();
        while (!mds.empty()) mds.pop();

        // pse + pge
        for (int i=0; i<sz; ++i) {
            while (!mis.empty() && nums[mis.top()] > nums[i]) mis.pop();
            pse[i] = mis.empty() ? -1 : mis.top();
            mis.push(i);

            while (!mds.empty() && nums[mds.top()] < nums[i]) mds.pop();
            pge[i] = mds.empty() ? -1 : mds.top();
            mds.push(i);
        }

        long long ans = 0;
        for (int i=0; i<sz; ++i) {
            ans += 1LL * (nge[i] - i) * (i - pge[i]) * nums[i];
            ans -= 1LL * (nse[i] - i) * (i - pse[i]) * nums[i];
            // maxes - mins
        }
        return ans;
    }
};