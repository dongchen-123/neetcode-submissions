class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int max = 0;
        std::vector<int> sub= {}; 
        std::priority_queue<int> maxHeap = {};
        if (nums.size() == 1) return nums[0];
        else {
            for (const auto& n : nums) {
                maxHeap.push(n);
                if (sub.empty()) {
                    if (n >= 0) {
                        sub.push_back(n);
                        max = (n >= max) ? n : max;
                        curSum = n;
                    }
                    else {
                        curSum = 0;
                    }
                }
                else {
                    if (curSum + n > 0){
                        if (curSum + n > max) {
                            max = curSum + n;
                        }
                        sub.push_back(n);
                        curSum += n;
                    }
                    else {
                        sub = {};
                        curSum = 0;
                    } 
                }
            }
        }
        if (max != 0) return max;
        else return maxHeap.top();
    }
};
