class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int cnt = 0;
        int startInd = -1;
        int min_len = s.size() + 1;
        vector<int> hash(256, 0);
        for (char ch: t) hash[ch]++;
        for (int right = 0; right < s.length(); ++right) {
            char ch = s[right];
            if (hash[ch] > 0) cnt++; // we still need a requirement from hash_t for this char, so increment the cnt
            hash[ch]--; // If we include a char into our window, whether it is in hash_t or not, we need to decrement it
            // if we don't a char in hash_t, this will end up negative here
            // if we have extra occurances of a char which is even in hash_t, we will end up negative here
            // hash[ch] > 0, we still have a requirement of the occurances of this char from hash_t, increment the count
            // hash[ch] <= 0, we may have completed the requirement of the occruances or maybe we got extra occurances of that char into our window
            while (cnt == t.size()) {
                if ((right - left + 1) < min_len) {
                    min_len = right - left + 1;
                    startInd = left;
                }
                hash[s[left]]++; // if we are removing a char from our winodw, whether it is in hash_t o not, we need to increment it
                if (hash[s[left]] > 0) cnt--; // like I said, we might have extra occurances of a char into our window, might end up with negative, so while we are removing whether we need have shortage of that char in our window, meaning hahs[s[left]] > 0, if its positive then we are shortage of that occurances from hash_t. !!!Important point here
                left++;
            }
        }
        return startInd == -1 ? "" : s.substr(startInd, min_len);
        // Ex. Traverse this example to understand more
        // s = "AAAAB" and t = "AAB" 
    }
};
// TC: O(N)
// SC: O(1)


class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0 || s.size() < t.size()) return "";

        unordered_map<char, int> mapp;
        for (char x : t) mapp[x]++;

        int required = mapp.size();
        int left = 0, right = 0;
        int got = 0;
        int ans[] = {-1, 0, 0};

        unordered_map<char, int> subStringMap;
        while (right < s.size()) {
            char x = s[right];
            subStringMap[x]++;
            if (mapp.find(x) != mapp.end() && mapp[x] == subStringMap[x]) {
                got++;
            }
            while (left <= right && required == got) {
                x = s[left];
                if (ans[0] == -1 || ans[0] >= (right - left + 1)) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                subStringMap[x]--;
                if (mapp.find(x) != mapp.end() && mapp[x] > subStringMap[x]) {
                    got--;
                }
                left++;
            }
            right++;
        }
        if (ans[0] == -1) return "";
        return s.substr(ans[1], ans[0]);
    }
};
