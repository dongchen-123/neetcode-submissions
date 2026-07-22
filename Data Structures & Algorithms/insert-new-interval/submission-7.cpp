class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        std::vector<vector<int>> out = {};
        if (intervals.empty()) return {newInterval};
        while (i < intervals.size() && newInterval[0] > intervals[i][0]) i++;
        if (i < intervals.size()) intervals.insert(intervals.begin()+i, newInterval);
        else intervals.push_back(newInterval);
        for (const auto& v : intervals) {
            if (out.empty()) out.push_back(v);
            else {
                if (v[0] <= out.back()[1]) {
                    if (v[1] > out.back()[1]) out.back()[1] = v[1];
                }
                else out.push_back(v);
            }
        }
        return out;
    }
};
