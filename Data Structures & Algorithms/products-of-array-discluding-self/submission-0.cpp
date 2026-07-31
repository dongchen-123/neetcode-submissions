class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre;
        vector<int> suf;
        vector<int> out;
        int pre_prod = 1;
        int suf_prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            pre_prod = (i !=0) ? pre_prod * nums[i-1] : pre_prod;
            pre.push_back(pre_prod);
        }
        for (int i = nums.size()-1; i >= 0; i--) {
            suf_prod = (i != nums.size()-1) ? suf_prod * nums[i+1] : suf_prod;
            suf.push_back(suf_prod);
        }
        for (int i = 0; i < nums.size(); i++) {
            out.push_back(pre[i] * suf[nums.size() - i - 1]);
        }
        return out;
    }
};
