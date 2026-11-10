class Solution {
public:
    void moveZeroes(vector<int>& arr) {
    // https://www.codingninjas.com/studio/problems/ninja-and-the-zero-s_6581958?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM
      int isZero = 0;
        int n = arr.size();
        while(isZero < n) {
            if(arr[isZero] == 0) break;
            else isZero++;
        }
        int nonZero = isZero + 1;
        while(isZero<n && nonZero<n) {
            if(arr[nonZero] != 0) {
                arr[isZero] = arr[nonZero];
                arr[nonZero] = 0;
                isZero++;
            } 
            nonZero++;
        }
        // return arr;
    }
};