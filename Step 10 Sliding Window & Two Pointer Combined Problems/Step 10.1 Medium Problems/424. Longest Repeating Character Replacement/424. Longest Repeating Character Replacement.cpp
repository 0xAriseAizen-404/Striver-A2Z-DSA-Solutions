class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0;
        int max_freq = 0;
        int max_len = 0;
        for (int right = 0; right < s.length(); ++right) {
            max_freq = max(max_freq, ++freq[s[right] - 'A']);
            if (((right-left+1) - max_freq) > k) --freq[s[left++] - 'A'];
            // I got valid answer Window10 with MaxFreq, but when I move to Window11, I got one wrong extra character, So I will keep moving this same Window11 sideways, Until I get valid answer meaning PreviousMaxFreq + 1, then I will get a valid answer.
            // AAABBAABBBBB (traverse it to understand this code)
            // 01234567891011
            // Valid answer till Window0_6 = 7Len(5A, 2B) - 5MaxFreq => 2Corrections
            // When I read 7th Index, I got One extra wrong character in Window0_7 = 8Len(5A, 3B) - 5MaxFreq => 3Corrections
            // So I will remove left_0 and move right++
            // now Window1_8 = 8Len(4A, 4B) - but MaxFreq stays 5, I need to look for greater MaxFreq Window, thats my valid window. => 3Corrections (but in reality its 4 Corrections, if we get real MaxFreq of this window)
            // move the winodw -> Window2_9 = 8Len(3A, 5B) - 5MaxFreq => 3Corrections, Move it
            // Window3_10 = 8Len(2A, 6B) - 6MaxFreq => 2Corrections -> Valid One, no need to move Left, Just extend the window, move right
            // Window3_11 = 9Len(2A, 7B) - 7MaxFreq => 2Corrections -> Valid One, no need to move Left, Just extend the window, move right
            // Came to End of the road. Valid Window3_11 - 9Len
            // Understand, if you got a InValid Window, then just move the window to find where the MaxFreq is PreviousMaxFreq + 1, then you will justify the statement Len - MaxFreq <= K
            // Its like I got this much of MaxFreq for the previous WindowSize, cna you give me More MaxFreq+1, in this Window, if you can give, then I won't increase Left, I will take this extended window size, otherwise I will increase left and keep the window size the last previous valid window size.
            // I know its a Lot, but read this twice, and then Dry run the example
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         vector<int> freq(26, 0);
//         int left = 0;
//         int max_freq = 0;
//         int max_len = 0;
//         for (int right = 0; right < s.length(); ++right) {
//             max_freq = max(max_freq, ++freq[s[right] - 'A']);
//             while (((right-left+1) - max_freq) > k) {
//                 --freq[s[left++] - 'A'];
//                 max_freq = *max_element(freq.begin(), freq.end());
//             }
//             max_len = max(max_len, right - left + 1);
//         }
//         return max_len;
//     }
// };

class Solution {
public:
    int characterReplacement(string s, int k) {
        int *chars = new int[26]();
        int left = 0;
        int right = 0;
        int maxFreq = 0;
        int maxLen = 0;
        while (right < s.length()) {
            maxFreq = max(maxFreq, ++chars[s[right] - 'A']);
            if ((right-left+1) - maxFreq > k) --chars[s[left++] - 'A'];
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};