class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int low = 1;
        int high = nums.size() - 2;
        if(nums[low] != nums[low - 1]) return nums[low - 1];
        if(nums[high] != nums[high + 1]) return nums[high + 1];
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid - 1] == nums[mid]) {
                if((mid & 1) == 1) low = mid + 1;
                else high = mid - 1;
            } else if(nums[mid] == nums[mid + 1]) {
                if((mid & 1) == 1) high = mid - 1;
                else low = mid + 1;
            } else return nums[mid];
        }
        return -1;
        
        
        
        
//         int right = nums.size() - 1;
//         int left = 0;
//         while (left < right) {
//             int mid = (left + right) / 2;
//             if (nums[mid] == nums[mid ^ 1]) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }
//         return nums[left];
    }
};