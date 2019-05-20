class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    const int m = matrix.size(), n = matrix.empty()? 0 : matrix[0].size();
    auto res = matrix;
    for (auto &vec: res) {
        for (auto &x: vec) {
            if (x != 0) { x = m + n; }  // set to upper bound
        }
    }
    for (int i = 0, h = m - 1; i < m; ++i, --h) {
        for (int j = 0, k = n - 1; j < n; ++j, --k) {
            if (i != 0) {   // not row border
                res[i][j] = std::min(res[i][j], res[i-1][j] + 1);
                res[h][j] = std::min(res[h][j], res[h+1][j] + 1);
            }
            if (j != 0) {   // not column border
                res[i][j] = std::min(res[i][j], res[i][j-1] + 1);
                res[i][k] = std::min(res[i][k], res[i][k+1] + 1);
                res[h][j] = std::min(res[h][j], res[h][j-1] + 1);
                res[h][k] = std::min(res[h][k], res[h][k+1] + 1);
            }
        }
    }
    return res;
}
};