class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row_num = -1;
        if (matrix.size() == 1) {
            for (const auto& n: matrix[0]) {
                if (n == target) return true;
                else if (n > target) return false;
            }
        }
        for (int i = 0; i < matrix.size(); i ++) {
            if (matrix[i][0] > target) {
                row_num = i-1;
                break;
            }
            else if (matrix[i][0] == target) return true;
            row_num = matrix.size()-1;
        }
        if (row_num == -1) return false;
        else {
            for (int i = 0; i < matrix[row_num].size(); i++) {
                if (matrix[row_num][i] == target) return true;
            }
        }
        return false;
    }
};
