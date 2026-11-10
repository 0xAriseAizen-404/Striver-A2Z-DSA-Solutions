class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        if (m == 0) {
            return false;
        }
        int n = mat[0].size();
        int left = 0;
        int right = m * n - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int midElement = mat[mid/n][mid%n];
            
            if(midElement == target) {
                return true;
            } else if(midElement < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};