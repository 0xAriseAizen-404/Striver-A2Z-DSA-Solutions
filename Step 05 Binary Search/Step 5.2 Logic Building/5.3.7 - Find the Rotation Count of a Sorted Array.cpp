class Solution {
public:
    int findKRotation(vector<int>& arr) {
        if (arr.empty()) return 0;

        int low = 0;
        int high = arr.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};