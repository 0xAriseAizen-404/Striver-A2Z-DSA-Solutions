class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointer for the end of the meaningful part of nums1
        int j = n - 1; // Pointer for the end of nums2
        int k = m + n - 1; // Pointer for the end of nums1

        // Iterate backwards through nums1 and nums2
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};


// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = 0;
//         int j = 0;
//         int temp = 0;
//         while (j < n) {
//             if (nums1[i] == 0) 
//                 nums1[i++] = nums2[j++];
//             else if (nums1[i] > nums2[j]) {
//                 temp = nums1[i];
//                 nums1[i] = nums2[j];
//                 nums2[j] = temp;
//                 j++;
//             } else
//                 i++;
//         }
//     }
// };