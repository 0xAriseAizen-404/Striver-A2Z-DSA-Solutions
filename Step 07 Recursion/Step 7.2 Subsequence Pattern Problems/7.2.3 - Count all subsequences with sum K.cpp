// DP APPROACH

class Solution {
public:
    int MOD = 1e9 + 7;

    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        
        // There's exactly one way to achieve a sum of 0: using no elements
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= sum; ++j) {
                // Case 1: Exclude the current element
                dp[i][j] = dp[i - 1][j];
                
                // Case 2: Include the current element (if it's not greater than the target sum)
                if (j >= arr[i - 1]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
                }
            }
        }
        
        return dp[n][sum];
    }
};


// RECURSIVE APPROACH

// class Solution{
// 	public:
// 	int MOD = 1e9 + 7;
	// int countDistinctSubsequences(int arr[], int n, int sum, int currSum, int index) {
    //     if (index == n) {
    //         if (currSum == sum) {
    //             return 1;
    //         }
    //         return 0;
    //     }

    //     // Case 1: Exclude the current character and move to the next
    //     int exclude = countDistinctSubsequences(arr, n, sum, currSum, index + 1);

    //     // Case 2: Include the current character and move to the next
    //     int include = countDistinctSubsequences(arr, n, sum, currSum + arr[index], index + 1);

    //     return (exclude + include) % MOD;
    // }

    // 	int perfectSum(int arr[], int n, int sum)
    // 	{
    //         // Your code goes here
    //         return countDistinctSubsequences(arr, n, sum, 0, 0);
    // 	}
// };