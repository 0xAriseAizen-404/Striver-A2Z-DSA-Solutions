class Solution{
	public:
	long long power(int base, int exp) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
            if (result > INT_MAX) {  // Early termination if result exceeds integer bounds
                return INT_MAX;
            }
        }
        return result;
    }
    
    int NthRoot(int n, int m)
    {
        // Code here.
        if (m == 0 || m == 1) {
            return m;
        }
        
        int low = 1, high = m;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long mid_pow = power(mid, n);
            
            if (mid_pow == m) {
                return mid;
            }
            else if (mid_pow < m) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
	}  
};