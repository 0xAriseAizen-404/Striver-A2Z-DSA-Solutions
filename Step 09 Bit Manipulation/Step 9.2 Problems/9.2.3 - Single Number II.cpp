class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for (const int &x: nums) {
            ones = (ones ^ x) & ~twos;
            twos = (twos ^ x) & ~ones;
        }
        return ones;

        // int ans = 0;
        // for (int bitInd=0; bitInd<32; ++bitInd) {
        //     int cnt = 0;
        //     for (int i=0; i<nums.size(); ++i) {
        //         if (nums[i] & (1 << bitInd)) cnt++;
        //     }
        //     if (cnt%3 == 1)
        //         ans |= (1 << bitInd);
        // }
        // return ans;


        // sort(nums.begin(), nums.end());
        // for (int i=1; i<nums.size(); i += 3) {
        //     if (nums[i] != nums[i-1]) return nums[i-1];
        // }
        // return nums.back();
    }
};