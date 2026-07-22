#include <stack>
class Solution {
public:
    void markLand (vector<vector<char>>& grid, int i, int j, std::stack<std::vector<int>>& grid_stack) {
        if (grid[i][j] == '1') {
            grid_stack.push({i, j});
            grid[i][j] = 0;
            std::vector<std::vector<int> > neighbours = {{i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}};
            for (const auto& n : neighbours) {
                if (n[0] >= 0 && n[0] < grid.size() && n[1] >= 0 && n[1] < grid[0].size() && n != grid_stack.top()) {
                    markLand (grid, n[0], n[1], grid_stack);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        std::stack<std::vector<int> > grid_stack;
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    markLand (grid, i, j, grid_stack);
                    count++;
                }
            }
        }
        return count;
    }
};
