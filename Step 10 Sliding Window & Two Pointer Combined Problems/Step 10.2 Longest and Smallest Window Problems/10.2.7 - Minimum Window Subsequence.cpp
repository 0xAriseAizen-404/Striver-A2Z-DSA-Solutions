// https://www.geeksforgeeks.org/problems/minimum-window-subsequence/1

class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        // Code here
        int n = s1.size();
        int m = s2.size();
        int min_len = n + 1;
        int start = -1;
        int ind_s1 = 0;
        while (ind_s1 < n) {
            int ind_s2 = 0;
            // forward pass
            while (ind_s1 < n) {
                if (s1[ind_s1] == s2[ind_s2]) ind_s2++;
                if (ind_s2 == m) break;
                ind_s1++;
            }
            if (ind_s1 == n) break;
            // backward pass
            int end = ind_s1;
            ind_s2 = m - 1;
            while (ind_s2 >= 0) {
                if (s1[ind_s1] == s2[ind_s2]) ind_s2--;
                ind_s1--;
            }
            ind_s1++; // actual start of the minimal window
            if (end - ind_s1 + 1 < min_len) {
                min_len = end - ind_s1 + 1;
                start = ind_s1;
            }
            // Continue Search
            ind_s1++;
        }
        return start == -1 ? "" : s1.substr(start, min_len);
    }
};