class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sz = arr.size();
        vector<int> nse(sz, sz);
        vector<int> pse(sz, -1);
        stack<int> st; // Minimum Increasing Stack;
        // NSE
        for (int i=sz-1; i>=0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? sz : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        // PSE
        for (int i=0; i<sz; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        // here we are counting the subarrays
        // so normally, nse >= &&&& pse >=, both are same tie breaking way.
        // but here in the counting subarray, we will get overlapping ambiguity i.e both numbers dominate same ranges, if we use same condition for both side, we need to use like nse >= && pse > (or) nse > && pse >=.

        // x GGSmall x small x x x small x x x GSmall x x x.

        // here if first case, both small_1 will have range from GGSmall to GSmall &&&& small_2 will have range from GGSmall to GSmall.
        // if in second case, small_1 will have range from GGSmall to GSmall &&&& small_2 will have range from small_1 to GSmall.
        // see the difference between ranges.
        int ans = 0;
        int mod = 1e9+7;
        for (int i=0; i<sz; ++i) {
            ans = (ans + 1LL * (nse[i] - i) * (i - pse[i]) * arr[i] % mod) % mod;
        }
        return ans;
    }
};