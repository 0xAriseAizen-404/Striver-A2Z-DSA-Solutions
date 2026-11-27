// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> umap;
//         for (int &x: nums) umap[x]++;
//         int ans = -1;
//         for (auto &x: umap) {
//             if (x.second == 1) {
//                 ans = x.first;
//                 break;
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int singleNumber(vector<int> &nums) {
//         sort(nums.begin(), nums.end());
//         int ans = nums[nums.size() - 1];
//         for (int i=0; i<nums.size()-1; i+=2) {
//             if (nums[i] != nums[i+1]) {
//                 ans = nums[i];
//                 break;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int _xor = 0;
        for (int &x: nums) _xor ^= x;
        return _xor;
    }
};