class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high) {
            int mid  = low + (high - low) / 2;
            long long totalHours = 0;  // Change to long long
            for(auto x : piles) 
                totalHours += ceil((double)x / (double)mid);
            if(totalHours <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};