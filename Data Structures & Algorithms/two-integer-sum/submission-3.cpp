class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen_nums;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (!seen_nums.count(complement)) {
                seen_nums.insert({nums[i], i});
            }
            else {
                if (i < seen_nums[complement]) return {i, seen_nums[complement]};
                
                else return {seen_nums[complement], i};
            }
        }
        
    }
};