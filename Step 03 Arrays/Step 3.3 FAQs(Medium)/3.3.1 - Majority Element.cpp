class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = nums[0];
        for (int i=0; i<nums.size(); ++i) {
            if (ele == nums[i]) count++;
            else if (ele != nums[i]) count--;
            if (count == 0) ele = nums[i + 1];
        }
        count = 0;
        for (auto &x: nums) if (x == ele) count++;
        return (count > (nums.size()/2)) ? ele : -1;
    }
};