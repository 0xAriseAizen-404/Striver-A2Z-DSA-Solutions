class Solution {
public:
    int beautySum(string s) {
        int n = (int)s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int freq[26] = {0};
            int maxFreq = 0;
            for (int j = i; j < n; ++j) {
                int idx = s[j] - 'a';
                ++freq[idx];
                maxFreq = max(maxFreq, freq[idx]);
                int minFreq = INT_MAX;
                for (int c = 0; c < 26; ++c) {
                    if (freq[c] > 0) minFreq = min(minFreq, freq[c]);
                }
                ans += (maxFreq - minFreq);
            }
        }
        return ans;
    }
};