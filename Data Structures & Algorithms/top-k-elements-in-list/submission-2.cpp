class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        std::vector<int> out = {};
        for(const auto& n : nums) freq[n]++;
        std::vector<std::vector<int>> buckets;
        buckets.assign(nums.size(), {});
        for (const auto& f : freq) buckets[f.second-1].push_back(f.first);
        for (int i = nums.size()-1; i >= 0; i--) {
            if (!buckets[i].empty() && out.size() != k) {
                for (const auto& v : buckets[i]) {
                    out.push_back(v);
                }
            }
            if (out.size() == k) return out;
        }
    }
};
