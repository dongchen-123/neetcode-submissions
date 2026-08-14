class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int> q;
        int count = 0;
        for (const auto& n : nums) q.push(n);
        if (k == 1) return q.top();
        else {
            while (count < k-1) {
                q.pop();
                count ++;
            }
            return q.top();
        }
    }
};
