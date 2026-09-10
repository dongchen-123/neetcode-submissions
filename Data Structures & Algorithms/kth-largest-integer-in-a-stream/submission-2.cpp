class KthLargest {
public:
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int k_n;
    KthLargest(int k, vector<int>& nums) {
        k_n = k;
        for (const auto& n : nums) {
            pq.push(n);
            if (pq.size() > k_n) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k_n) pq.pop();
        return pq.top();
        
    }
};
