class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map <char, int> char_s, char_t;
        for (auto c : s) {
            char_s[c] ++;
        }
        for (auto c : t) {
            char_t[c] ++;
        }
        return (char_s == char_t);
    }
};
