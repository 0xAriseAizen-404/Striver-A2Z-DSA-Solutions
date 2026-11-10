class Solution {
private:
    void helper(int n, vector<string> &board, int row, vector<vector<string>> &ans, vector<int> &topCol, vector<int> &currToTopRight, vector<int> &currToTopLeft) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col=0; col<n; ++col) {
            if (topCol[col] == 0 && currToTopRight[row + col] == 0 && currToTopLeft[(n - 1) + (col - row)] == 0) {

                board[row][col] = 'Q';
                topCol[col] = 1;
                currToTopRight[row + col] = 1;
                currToTopLeft[(n - 1) + (col - row)] = 1;

                helper(n, board, row + 1, ans, topCol, currToTopRight, currToTopLeft);

                board[row][col] = '.';
                topCol[col] = 0;
                currToTopRight[row + col] = 0;
                currToTopLeft[(n - 1) + (col - row)] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i=0; i<n; ++i) board[i] = s;
        vector<int> topCol(n, 0), currToTopRight(2*n-1, 0), currToTopLeft(2*n-1, 0);
        helper(n, board, 0, ans, topCol, currToTopRight, currToTopLeft);
        return ans;
    }
};


// class Solution {
// private:
//     bool isSafe(int n, vector<string> &board, int row, int col) {
//         int temp_row = row;
//         int temp_col = col;
//         while (row >= 0 && col >= 0) {
//             if (board[row][col] == 'Q') return false;
//             row--; col--;
//         }
//         row = temp_row;
//         col = temp_col;
//         while (row >= 0) {
//             if (board[row][col] == 'Q') return false;
//             row--;
//         }
//         row = temp_row;
//         col = temp_col;
//         while (row >= 0 && col < n) {
//             if (board[row][col] == 'Q') return false;
//             row--; col++;
//         }
//         return true;
//     }
//     void helper(int n, vector<string> &board, int row, vector<vector<string>> &ans) {
//         if (row == n) {
//             ans.push_back(board);
//             return;
//         }
//         for (int col=0; col<n; ++col) {
//             if (isSafe(n, board, row, col)) {
//                 board[row][col] = 'Q';
//                 helper(n, board, row + 1, ans);
//                 board[row][col] = '.';
//             }
//         }
//     }
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n, '.');
//         for (int i=0; i<n; ++i) board[i] = s;
//         helper(n, board, 0, ans);
//         return ans;
//     }
// };