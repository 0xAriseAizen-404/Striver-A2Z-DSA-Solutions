// https://www.naukri.com/code360/problems/distinct-characters_2221410

#include<bits/stdc++.h>
int kDistinctChars(int k, string &str) {
    // Write your code here
    int *hash = new int[26]();
    int left = 0;
    int cnt = 0;
    int max_len = 0;
    for (int right = 0; right < str.length(); ++right) {
        ++hash[str[right] - 'a'];
        if (hash[str[right] - 'a'] == 1) cnt++;
        while (cnt > k) {
            --hash[str[left] - 'a'];
            if (hash[str[left] - 'a'] == 0) cnt--;
            left++;
        }
        max_len = max(max_len, right - left + 1);
    }
    return max_len;
}