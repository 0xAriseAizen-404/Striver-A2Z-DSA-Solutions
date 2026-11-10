class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> PascalTriangle;
        for (int i=0; i<numRows; ++i) {
            vector<int> row(i+1, 1);
            for (int x=1; x<i; ++x) {
                row[x] = PascalTriangle[i-1][x-1] + PascalTriangle[i-1][x];
            }
            PascalTriangle.push_back(row);
        }
        return PascalTriangle;
    }
};