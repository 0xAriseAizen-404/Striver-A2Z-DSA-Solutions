class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int _count = 1;
            int _sum = 0;
            for (int i=0; i<nums.size(); ++i) {
                if (_sum + nums[i] <= mid) _sum += nums[i];
                else _count++, _sum = nums[i];
            }
            if (_count > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};