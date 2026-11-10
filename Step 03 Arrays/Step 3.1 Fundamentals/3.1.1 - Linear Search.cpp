class Solution {
public:
    int linearSearch(const vector<int>& nums, int target) {
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == target) {
                return index;
            }
        }
        return -1;
    }
};