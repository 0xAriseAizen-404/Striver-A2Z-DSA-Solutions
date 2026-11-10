class Solution {
  private:
    bool isSafe(int node, int v, vector<vector<int>> &edges, vector<int> &color, int col) {
        for (auto &x: edges) {
            if (x[0] == node && color[x[1]] == col) return false;
            if (x[1] == node && color[x[0]] == col) return false;
        }
        return true;
    }
    bool helper(vector<int> &color, int node, int v, vector<vector<int>> &edges, int m) {
        if (node == v) return true;
        for (int i=1; i<=m; ++i) {
            if (isSafe(node, v, edges, color, i)) {
                color[node] = i;
                if (helper(color, node + 1, v, edges, m)) return true;
                color[node] = 0;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> color(v, 0);
        return helper(color, 0, v, edges, m);
    }
};