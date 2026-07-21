class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen;
        int max_length = 0;
        int i = 0;
        int j = 0;
        while ( j < s.length()) {
            if (!seen.count(s[j])) {
                seen.insert(s[j]);
                j++;
            }
            else {
                seen.erase(s[i]);
                i++;
            }
            int len = j - i;
            max_length = max(len, max_length);
        }
        return max_length;
        


    }
};
