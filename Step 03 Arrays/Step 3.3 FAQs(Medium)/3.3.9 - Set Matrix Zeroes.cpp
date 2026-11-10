class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> p;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j]==0)
                    p.push_back({i, j});
            }
        }
        for(auto x : p){
            for(int i=0;i<m;++i) mat[x.first][i] = 0;
            for(int j=0;j<n;++j) mat[j][x.second] = 0;
        }
    }
};