class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_len = 0;
        int zeroes = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) zeroes++;
            while (zeroes > k) {
                if (nums[left++] == 0) zeroes--;
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int tempK = k;
//         int left = 0;
//         int max_len = 0;
//         for (int right = 0; right < nums.size(); ++right) {
//             if (nums[right] == 0) {
//                 tempK -= 1;
//                 while (tempK < 0) {
//                     if (nums[left++] == 0) tempK++;
//                 }
//             }
//             max_len = max(max_len, right - left + 1);
//         }
//         return max_len;
//     }
// };

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0;
        int max_len = 0;

        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zeros++;
            }
            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            max_len = max(max_len, right-left+1);
        }
        return max_len;
    }
};