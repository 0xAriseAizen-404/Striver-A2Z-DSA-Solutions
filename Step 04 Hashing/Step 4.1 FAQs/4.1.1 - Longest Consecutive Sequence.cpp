class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int max_seq = 0;
        for (int x : st) {
            if (!st.count(x - 1)) {
                int curr = x;
                while (st.count(curr)) curr++;
                max_seq = max(max_seq, curr - x);
            }
        }
        return max_seq;
    }
};
