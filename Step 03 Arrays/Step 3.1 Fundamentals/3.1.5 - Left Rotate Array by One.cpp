class Solution {
public:
    void leftRotateByOne(vector<int>& nums) {
        int n = nums.size();
 
        // Arrays with at most one element remain unchanged.
        if (n <= 1) {
            return;
        }
 
        vector<int> temp(n);
 
        // Shift every element except the first one position to the left.
        for (int index = 1; index < n; index++) {
            temp[index - 1] = nums[index];
        }
 
        // The original first element moves to the last position.
        temp[n - 1] = nums[0];
 
        // Copy the rotated arrangement back into the original array.
        for (int index = 0; index < n; index++) {
            nums[index] = temp[index];
        }
    }
};