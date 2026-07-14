class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map <int, int> sorted_nums;
        for (const auto& n : nums) sorted_nums[n] ++;
        std::vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& m : sorted_nums) {
            int element = m.first;
            int freq = m.second;
            buckets[freq].push_back(element);
        }
        
        std::vector <int> out;
        int count = 0;
        for (int i = nums.size(); i > 0; i --) {
            for (const auto& n : buckets[i]) {
                out.push_back(n);
                count ++;
                if (count == k) return out;
            }
        }
    }
};
