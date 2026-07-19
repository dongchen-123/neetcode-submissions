class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> seen_set;
        for (const auto& n : nums) {
            if (seen_set.find(n)!=seen_set.end()) return true;
            else seen_set.insert(n);
        }
        return false;
    }
};