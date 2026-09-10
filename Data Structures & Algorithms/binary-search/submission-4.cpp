class Solution {
public:
    int search(vector<int>& nums, int target) {
        int search_min = 0; 
        int search_max = nums.size()-1;
        int mid;
        while (search_max >= search_min) {
            mid = (search_max + search_min) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) search_max = mid - 1;
            else search_min = mid + 1;
        }
        return -1;
    }
};
