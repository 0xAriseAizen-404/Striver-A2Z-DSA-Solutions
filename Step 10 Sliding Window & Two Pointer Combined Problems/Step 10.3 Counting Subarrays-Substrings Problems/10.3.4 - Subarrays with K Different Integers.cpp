// Optimal Solution
class Solution {
private:
    int helper(vector<int> &nums, int k) {
        int left = 0;
        int cnt = 0;
        unordered_map<int, int> umap;
        for (int right = 0; right < nums.size(); ++right) {
            ++umap[nums[right]];
            while (umap.size() > k) {
                --umap[nums[left]];
                if (umap[nums[left]] == 0) umap.erase(nums[left]);
                left++;
            }
            cnt += (right - left + 1);
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if (k == 1) return helper(nums, k);
        return helper(nums, k) - helper(nums, k-1);
    }
};
// TC: O(2N)
// SC: O(K)

// BruteForce Solution
// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         int sz = nums.size();
//         int cnt = 0;
//         for (int i = 0; i < sz; i++) {
//             unordered_map<int, int> umap;
//             for (int j = i; j < sz; j++) {
//                 umap[nums[j]]++;
//                 if (umap.size() == k) cnt++;
//                 else if (umap.size() > k) break;
//             }
//         }
//         return cnt;
//     }
// };
// TC: O(N^2)
// SC: O(K)


class Solution {
private:
    int myHelper(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int right = 0;
        int count = 0;
        while (right < nums.size()) {
            freq[nums[right]]++;
            while (freq.size() > k) {
                if (--freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return myHelper(nums, k) - myHelper(nums, k - 1);
    }
};


// class Solution {
// private:
//     int myHelper(vector<int>& nums, int k) {
//         unordered_set<int> sset;
//         int left = 0;
//         int right = 0;
//         int count = 0;
//         while (right < nums.size()) {
//             sset.insert(nums[right]);
//             while (sset.size() > k) sset.erase(nums[left++]);
//             count += (right - left + 1);
//             right++;
//         }
//         return count;
//     }
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         return myHelper(nums, k) - myHelper(nums, k - 1);
//     }
// };