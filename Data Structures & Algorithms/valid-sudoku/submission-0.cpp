class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> row_map;
        std::unordered_map<int, std::unordered_set<char>> col_map;
        std::unordered_map<int, std::unordered_set<char>> grid_map;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (row_map[i].count(board[i][j]) ||
                    col_map[j].count(board[i][j]) ||
                    grid_map[(i/3)*3+(j/3)].count(board[i][j])) {
                        return false;
                    }
                else {
                    row_map[i].insert(board[i][j]);
                    col_map[j].insert(board[i][j]);
                    grid_map[(i/3)*3+(j/3)].insert(board[i][j]);
                }
            }
        }
        return true;
    }
};
