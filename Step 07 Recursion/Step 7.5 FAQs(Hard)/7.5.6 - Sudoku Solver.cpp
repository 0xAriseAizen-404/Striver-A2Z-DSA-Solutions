class Solution {
private:
    int row[9] = {0};
    int col[9] = {0};
    int box[9] = {0};
    bool helper(vector<vector<char>> &board, int r, int c) {
        if (r == 9) return true;
        if (c == 9) return helper(board, r + 1, 0);
        if (board[r][c] != '.') return helper(board, r, c + 1);
        for (int num=1; num<=9; ++num) {
            int mask = 1 << num;
            int b = 3 * (r / 3) + (c / 3);
            if (!(row[r]&mask) && !(col[c]&mask) && !(box[b]&mask)) {
                board[r][c] = num + '0';
                row[r] |= mask;
                col[c] |= mask;
                box[b] |= mask;
                if (helper(board, r, c + 1)) return true;
                board[r][c] = '.';
                row[r] ^= mask;
                col[c] ^= mask;
                box[b] ^= mask;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>> &board) {
        for (int r=0; r<9; ++r) {
            for (int c=0; c<9; ++c) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '0';
                    int mask = 1 << num;
                    int b = 3 * (r / 3) + (c / 3);
                    row[r] |= mask;
                    col[c] |= mask;
                    box[b] |= mask;
                }
            }
        }
        helper(board, 0, 0);
    }
};


// MyVersion
// class Solution {
// private:
//     bool isValid(vector<vector<char>> &board, int row, int col, char c) {
//         for (int x=0; x<9; x++) {
//             if (board[row][x] == c) return false;
//             if (board[x][col] == c) return false;
//             int boxRow = 3 * (row / 3) + (x / 3);
//             int boxCol = 3 * (col / 3) + (x % 3);
//             if (board[boxRow][boxCol] == c) return false;
//         }
//         return true;
//     }
//     bool solve(vector<vector<char>> &board, int row, int col) {
//         if (row == 9) return true;
//         if (col == 9) return solve(board, row + 1, 0);
//         if (board[row][col] != '.') return  solve(board, row, col + 1);
//         for (char c = '1'; c <= '9'; c++) {
//             if (isValid(board, row, col, c)) {
//                 board[row][col] = c;
//                 if (solve(board, row, col + 1)) return true;
//                 board[row][col] = '.';
//             }
//         }
//         return false;
//     }
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board, 0, 0);
//     }
// };


// Others Version
// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }
//     bool solve(vector<vector<char>>& board) {
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 if (board[i][j] == '.') {
//                     for (char c = '1'; c <= '9'; c++) {
//                         if (isValid(board, i, j, c)) {
//                             board[i][j] = c;
//                             if (solve(board)) return true;
//                             board[i][j] = '.';
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
//     bool isValid(vector<vector<char>>& board, int row, int col, char c) {
//         for (int i = 0; i < 9; i++) {
//             if (board[row][i] == c) return false;
//             if (board[i][col] == c) return false;
//             if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
//         }
//         return true;
//     }
// };