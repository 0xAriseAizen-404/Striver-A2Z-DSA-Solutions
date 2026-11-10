7.1.1 - Pow(x, n) - Pow(X, N)
7.1.2 - generate paranthesis - Helper function
7.1.3 - power set - Mask Bit Manipulation && Helper take or no take Pattern
7.1.4 - count good numbers - count_helper(k) - count_helper(k - 1)
7.1.5 - reverse a stack - empty the stack then insert at bottom

7.2.2 - check if there is a subsequence with k - include || exclude
7.2.3 - count all subsequences with k - include + exclude
7.2.4 - generate all binary susbtring without consecutive 1's - helper take or no take with take condition back() != 1

7.3.1 - combination sum 1 - helper - take & ind - no take & ind + 1 - track of sum
7.3.2 - combination sum 2 - sort - helper - all take with for loop and skip duplicates - track of sum
7.3.3 - power set - mask bit manipulation && helper take or no take pattern
7.3.4 - power set - mask bit manipulation with set && helper - all take with for loop and skip duplicates
7.3.5 - combination sum 3 - helper - all take with for loop start to 9 (start = 1)

7.4.1 - letter combinations of phone number - character map - helper - all take with for loop with each mapping characters

7.5.1 - palidromic partitioning - helper - for loop k from ind to N, check the substring palindrome or not, if helper(k + 1)
7.5.2 - word search - loop over through the grid, get the starting char of the word, start the search - substitute the character with '$' any char to know it is already visited - use flood fill algorithm
7.5.3 - N Queen - topCol[col], currToTopRight[row + col], currToTopLeft[n-1 + col-row], go from row 0 to n-1, check these three things, subsititute with 'Q' go to next row, if all works and goes to row == n, then return the board, else backtrack and remove the subsititude with '.' and those three things also.
7.5.4 - Rat in a Maze - if the current cell is 1, go and use substitute + flood fill algorithm to move to last cell
7.5.5 - 
7.5.6 - sudoku solver - 
