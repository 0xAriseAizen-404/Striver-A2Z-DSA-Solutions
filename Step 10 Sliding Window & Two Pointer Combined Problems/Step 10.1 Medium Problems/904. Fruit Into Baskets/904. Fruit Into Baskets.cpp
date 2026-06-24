// My Own Approach, but some little mistakes are there, ChatGPT Perfected it.
// Optimal Solution
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int basket1 = -1, basket1_cnt = 0;
        int basket2 = -1, basket2_cnt = 0;
        int left = 0;
        int max_len = 0;
        for (int right = 0; right < fruits.size(); ++right) {
            if (basket1 == -1 || basket1 == fruits[right]) {
                basket1 = fruits[right];
                basket1_cnt++;
            } else if (basket1 == -1 || basket2 == fruits[right]) {
                basket2 = fruits[right];
                basket2_cnt++;
            } else {
                // Got Third Type of Fruits
                while (basket1 != -1 && basket2 != -1) {
                    if (fruits[left] == basket1) {
                        basket1_cnt--;
                        if (basket1_cnt == 0) basket1 = -1;
                    } else {
                        basket2_cnt--;
                        if (basket2_cnt == 0) basket2 = -1;
                    }
                    left++;
                }
                if (basket1 == -1) {
                    basket1 = fruits[right];
                    basket1_cnt = 1;
                }
                if (basket2 == -1) {
                    basket2 = fruits[right];
                    basket2_cnt = 1;
                }
            }
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
// TC: O(N)
// SC: O(1)

// Better Solution
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         unordered_map<int, int> cnt;
//         int left = 0;
//         int ans = 0;
//         for (int right = 0; right < fruits.size(); right++) {
//             cnt[fruits[right]]++;
//             while (cnt.size() > 2) { // if (cnt.size() > 2) // same implementation as 424. Longest Repeating Character Replacement
//                 cnt[fruits[left]]--;
//                 if (cnt[fruits[left]] == 0)
//                     cnt.erase(fruits[left]);
//                 left++;
//             }
//             ans = max(ans, right - left + 1);
//         }
//         return ans;
//     }
// };
// TC: O(N)
// SC: O(1) // Mostly 3 Values will be stores in Map at a time


class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        unordered_map<int, int> fruitCount;
        int left = 0;
        int right = 0;
        int res = 0;
    
        while (right < arr.size()) {
            fruitCount[arr[right]]++;
    
            // Shrink the window if we have more than 2 types of fruits
            while (fruitCount.size() > 2) {
                fruitCount[arr[left]]--;
                if (fruitCount[arr[left]] == 0) {
                    fruitCount.erase(arr[left]);
                }
                left++;
            }
    
            res = max(res, right - left + 1);
            right++;
        }
    
        return res;
    }
};