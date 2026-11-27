class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, -1);
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < s.length(); ++right) {
            if (freq[s[right]] >= left) left = freq[s[right]] + 1;
            // checking if I have seen it or not, if I have not seen it then it will be like -1 >= leftInd (wrong).
            // If I seen it, then previousIndOfRight >= leftInd (right), then leftInd = previousIndOfRight + 1;

            freq[s[right]] = right; // saving the index where I seen it
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         set<char> ss;
//         int left = 0;
//         int max_len = 0;
//         for (int right = 0; right < s.length(); ++right) {
//             if (!ss.insert(s[right]).second) {
//                 while (s[left] != s[right]) ss.erase(s[left++]);
//                 ss.erase(s[left++]);
//                 ss.insert(s[right]);
//             }
//             max_len = max(max_len, (int)ss.size());
//         }
//         return max_len;
//     }
// };




class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        std::unordered_set<char> charSet;
        while (right < s.length()) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.emplace(s[right]);
                maxLen = std::max(maxLen, right - left + 1);
                right++;
            } else {
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxLen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        // int *hash = new int[256];
        // int hash[256];
        // fill_n(hash, 256, -1);
        // int hash[256] = { [0 ... 255] = -1 };
        array<int, 256> hash;
        hash.fill(-1);
        while (right < s.length()) {
            int ind = (int)s[right];
            if (hash[ind] == -1 || hash[ind] < left) {
                hash[ind] = right;
            } else {
                left = hash[ind] + 1;
                hash[ind] = right;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};