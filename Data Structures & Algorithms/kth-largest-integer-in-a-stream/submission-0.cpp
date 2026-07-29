class KthLargest {
public:
    int k_n;
    std::priority_queue <int, std::vector<int>, std::greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        k_n = k;
        for (const auto& n : nums) {
            if (pq.size() <= k-1) pq.push(n);
            else {
                pq.push(n);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k_n) pq.pop();
        return pq.top();
    }
};
