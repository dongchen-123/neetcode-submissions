class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> minHeap;
        for (int i = 0; i < points.size(); i++) {
            minHeap.push({points[i][0]*points[i][0]+ points[i][1]*points[i][1], i});
        }

        int count = 0;
        std::vector<vector<int>> out;
        while (count < k) {
            out.push_back(points[minHeap.top().second]);
            minHeap.pop();
            count++;
        }
        return out;
    }
};
