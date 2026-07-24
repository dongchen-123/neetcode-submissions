class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> maxHeap;
        for (const auto& s : stones) maxHeap.push(s);
        while (maxHeap.size() > 1) {
            int max1 = maxHeap.top();
            maxHeap.pop();
            int max2 = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(max1 - max2);
        }
        return maxHeap.top();
    }
};
