class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (m*k)) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            int tracker = 0;
            for(int x : bloomDay) {
                if(x <= mid) tracker++;
                else {
                    count += tracker/k;
                    tracker = 0;
                }
            }
            count += tracker/k;
             if(count >= m) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};