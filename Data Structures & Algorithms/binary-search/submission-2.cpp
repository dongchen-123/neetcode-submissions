class Solution {
public:
    int search(vector<int>& nums, int target) {
        int search_min = 0; 
        int search_max = nums.size()-1;
        int search_range = search_max - search_min + 1;
        while (search_range >= 2) {
            if (search_range % 2 != 0) {
                if (target == nums[(search_min + search_max) / 2]) return ((search_min + search_max) / 2);
                else if ((target < nums[(search_min + search_max) / 2])) search_max = ((search_min + search_max) / 2) - 1;
                else search_min = ((search_min + search_max) / 2) + 1;
            }
            else {
                if (target == nums[(search_min + search_max) / 2]) return (((search_min + search_max) / 2));
                else if (target == nums[((search_min + search_max) / 2)+1]) return (((search_min + search_max) / 2)+1);
                else if (target < nums[(search_min + search_max) / 2]) search_max = ((search_min + search_max) / 2) - 1;
                else if (target > nums[((search_min + search_max) / 2)+1]) search_min = ((search_min + search_max) / 2)+2;
                else return -1;
            }
            search_range = search_max - search_min + 1;
        }
        if (search_min > search_max) return -1;
        else if (target == nums[search_min]) return search_min;
        else return -1;
    }
};
