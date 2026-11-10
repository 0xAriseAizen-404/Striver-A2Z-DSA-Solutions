class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int missingNums = arr[mid] - (mid + 1);
            if(missingNums < k) low = mid + 1;
            else high = mid - 1;
        }
        // formula:
        // arr[high] + more
        // arr[high] + k - missingNums;
        // arr[high] + k - (arr[high] - (high + 1));
        // high + 1 + k;
        // low = high + 1 -> where traversing stops in BSearch;
        return low + k;
    }
};