class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};

        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        std::vector<int> out;
        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; c++) out.push_back(matrix[top][c]);
            top++;
            for (int r = top; r <= bottom; r++) out.push_back(matrix[r][right]);
            right--;
            if (bottom >= top){
                for (int c = right; c >= left; c--) out.push_back(matrix[bottom][c]);
                bottom--;
            }
            if (right >= left){
                for (int r = bottom; r >= top; r--) out.push_back(matrix[r][left]);
                left++;
            }
        }
        return out;
    }
};
