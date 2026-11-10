// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        long long int ans = 0;
        int low = 0;
        int high = (int) x;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long int res = (long long int) mid * mid;
            if (res <= x) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};