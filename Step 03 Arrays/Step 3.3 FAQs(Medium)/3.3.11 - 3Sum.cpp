class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int x = 0; x < n - 2; ++x) {
            if (x > 0 && nums[x] == nums[x - 1]) continue;
            int left = x + 1;
            int right = n - 1;
            while (left < right) {
                int summ = nums[x] + nums[left] + nums[right];
                if (summ == 0) {
                    ans.push_back({nums[x], nums[left++], nums[right--]});
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (right > left && nums[right] == nums[right + 1]) right--;
                }
                else if(summ < 0) left++;
                else right--;
            }
        }
        return ans;
    }
};