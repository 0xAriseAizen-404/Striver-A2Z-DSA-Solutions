class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        vector<int> ans;
        if (arr.empty()) return ans;
        int top = 0, left = 0;
        int bottom = arr.size() - 1, right = arr[0].size() - 1;
        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; ++i) ans.push_back(arr[top][i]);
            top++;
            for (int i = top; i <= bottom; ++i) ans.push_back(arr[i][right]);
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; --i) ans.push_back(arr[bottom][i]);
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; --i) ans.push_back(arr[i][left]);
                left++;
            }
        }
        return ans;
    }
};