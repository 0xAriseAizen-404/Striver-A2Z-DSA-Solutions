// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        
        // int sz = mat.size();
        // for (int i=0; i<sz; ++i) {
        //     int row = 0;
        //     int col = 0;
        //     for (int j=0; j<sz; ++j) {
        //         row += mat[i][j];
        //         col += mat[j][i];
        //     }
        //     if ((row == 1) && (col == sz)) return i;
        // }
        // return -1;
        
        int sz = mat.size();
        int top = 0;
        int bottom = sz - 1;
        while (top < bottom) {
            // celebrity is someone, who don't know anyone
            if (mat[top][bottom] == 1) top += 1; // does top know bottom, then its cannot be a celebrity
            else if (mat[bottom][top] == 1) bottom -= 1; // does bottom know top, then its cannot be a celebrity
            else {
                // top and bottom, don't know each other, then they both can't be a celebrity
                // cause someone has to know one, celebrity is someone who knows by all
                // either top=0, bottom=1 OR top=1, bottom=0
                
                // lets see in this case
                // top == 0, means top doesn't know bottom, but then at the same time, bottom has to know top right.
                // that means top == 0 && bottom == 1, should be it. then "else if" will execute
                // but it comes to "else" case, meaning, top=0, bottom=0, no one knows by anyone, so no one can be celebrity.
                // both cannot be celebriy, one has to know other
                top += 1;
                bottom -= 1;
            }
        }
        if (top > bottom) return -1;
        // top == bottom
        for (int i=0; i<sz; ++i) {
            if ((mat[top][i]==0 && mat[i][bottom]==1) || i==top) continue;
            else return -1;
        }
        return top;
    }
};