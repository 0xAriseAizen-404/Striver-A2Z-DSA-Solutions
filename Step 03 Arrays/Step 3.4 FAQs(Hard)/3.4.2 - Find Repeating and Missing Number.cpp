class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> hash(n);
        vector<int> ans(2);
        for(int i: arr){
            hash[i-1]++;
        }
        for(int i = 0; i < n; i++){
            if(hash[i] == 2){
                ans[0] = i+1 ;
            }
            if(hash[i] == 0){
                ans[1] = i+1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    // Finds the duplicate and missing numbers using sums and square sums.
    vector<int> findNumbers(vector<int>& nums) {
        long long n = nums.size();
        long long actualSum = 0;
        long long actualSquareSum = 0;

        // Accumulate the two actual totals using wide integers.
        for (long long value : nums) {
            actualSum += value;
            actualSquareSum += value * value;
        }

        long long expectedSum = n * (n + 1) / 2;
        long long expectedSquareSum = n * (n + 1) * (2 * n + 1) / 6;
        long long difference = actualSum - expectedSum;
        long long sumOfAnswers = (actualSquareSum - expectedSquareSum) / difference;

        // Use the sum and difference of the answers to find both numbers.
        long long repeating = (difference + sumOfAnswers) / 2;
        long long missing = repeating - difference;
        return {(int)repeating, (int)missing};
    }
};