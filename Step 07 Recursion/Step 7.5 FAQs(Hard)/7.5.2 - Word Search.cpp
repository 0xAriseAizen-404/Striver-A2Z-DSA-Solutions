class Solution {
private:
    bool helper(vector<vector<char>> &board, string word, int row, int col, int ind) {
        if (ind == word.size()) return true;
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[ind]) 
            return false;
        char temp = board[row][col];
        board[row][col] = '$';
        bool found = helper(board, word, row - 1, col, ind + 1) ||
                     helper(board, word, row + 1, col, ind + 1) ||
                     helper(board, word, row, col - 1, ind + 1) ||
                     helper(board, word, row, col + 1, ind + 1);
        board[row][col] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (helper(board, word, row, col, 0))
                    return true;
            }
        }
        return false;
    }
};


// This is Wrong, Because It goes for previous cell too...
// class Solution {
// private:
//     bool helper(vector<vector<char>> &board, string word, int row, int col, string lookup, int ind) {
//         if (row >= board.size() || col >= board[0].size() ||
//             row < 0 || col < 0) return false;
//         if (ind >= word.size()) return true;
//         if (word[ind] == board[row][col]) {
//             return helper(board, word, row - 1, col, lookup + board[row][col], ind + 1) ||
//             helper(board, word, row + 1, col, lookup + board[row][col], ind + 1) ||
//             helper(board, word, row, col - 1, lookup + board[row][col], ind + 1) ||
//             helper(board, word, row, col + 1, lookup + board[row][col], ind + 1);
//         }
//         return false;
//     }
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         for (int row = 0; row < board.size(); row++) {
//             for (int col = 0; col < board[0].size(); col++) {
//                 if (word[0] == board[row][col]) {
//                     if (helper(board, word, row - 1, col, to_string(board[row][col]), 1) ||
//                         helper(board, word, row + 1, col, to_string(board[row][col]), 1) ||
//                         helper(board, word, row, col - 1, to_string(board[row][col]), 1) ||
//                         helper(board, word, row, col + 1, to_string(board[row][col]), 1))
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };