class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort (intervals.begin(), intervals.end());
        std::vector<vector<int>> out = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][1] > out.back()[1] && intervals[i][0] <= out.back()[1]) {
                out.back()[1] = intervals[i][1];
            }
            else if (intervals[i][0] > out.back()[1]) out.push_back(intervals[i]);
        }
        return out;
    }
};
