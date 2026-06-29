class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0);
        int max_area = 0;

        for (vector<char> &row: matrix) {
            for (int i=0; i<cols; ++i) {
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            }
            int sz = heights.size();
            stack<int> pse;
            for (int nse=0; nse<=sz; ++nse) {
                while (!pse.empty() && (nse==sz || heights[pse.top()] >= heights[nse])) {
                    int height = heights[pse.top()]; pse.pop();
                    int width = nse - (pse.empty() ? -1 : pse.top()) - 1;
                    max_area = max(max_area, height * width);
                }
                pse.push(nse);
            }
        }
        return max_area;
    }
};

// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         vector<int> heights(cols + 1, 0);
//         int max_area = 0;

//         for (vector<char> &row: matrix) {
//             for (int i=0; i<cols; ++i) {
//                 heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
//             }
//             int sz = heights.size();
//             for (int i=0; i<sz; ++i) {
//                 for (int j=i, minH=INT_MAX; j<sz; ++j) {
//                     minH = min(minH, heights[j]);
//                     max_area = max(max_area, minH * (j - i + 1));
//                 }
//             }
//         }
//         return max_area;
//     }
// };