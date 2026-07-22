class Solution {
public:
    void markLand (vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            std::vector<std::vector<int> > neighbours = {{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}};
            for (const auto& n : neighbours) {
                if (n[0] >= 0 && n[0] < grid.size() && n[1] >= 0 && n[1] < grid[0].size()) {
                    markLand (grid, n[0], n[1]);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    markLand (grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
