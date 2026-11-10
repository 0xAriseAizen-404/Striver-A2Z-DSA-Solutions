class Solution {
  private:
    void helper(vector<vector<int>> &maze, int row, int col, string path, vector<string> &ans) {
        int n = maze.size();
        if (row >= n || col >= n|| row < 0 || col < 0) return;
        if (maze[row][col] == 0) return;
        if (row == n-1 && col == n-1) {
            ans.push_back(path);
            return;
        }
            
        maze[row][col] = 0;
        helper(maze, row+1, col, path+"D", ans);
        helper(maze, row, col-1, path+"L", ans);
        helper(maze, row, col+1, path+"R", ans);
        helper(maze, row-1, col, path+"U", ans);
        maze[row][col] = 1;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        helper(maze, 0, 0, "", ans);
        // sort(maze.begin(), maze.end());
        return ans;
    }
};