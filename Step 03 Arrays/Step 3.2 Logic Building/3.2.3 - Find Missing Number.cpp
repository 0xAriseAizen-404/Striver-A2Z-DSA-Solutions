class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),sum = n*(n+1)/2;
        int summ = accumulate(nums.begin(),nums.end(),0);
        return sum - summ;
    }
};