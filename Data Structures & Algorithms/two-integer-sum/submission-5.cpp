class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int, int> num_map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_map.count(complement)) {
                if (num_map[complement] < i) return {num_map[complement], i};
                else return {i, num_map[complement]};
            }
            else num_map[nums[i]] = i;
        }
    }
};
