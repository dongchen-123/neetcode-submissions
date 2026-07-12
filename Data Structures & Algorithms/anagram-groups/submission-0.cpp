class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string> > groups;
        for (auto s : strs) {
            int char_count[26] = {0};
            std::string key;
            for (char c : s) char_count[c - 'a']++;
            for (int i = 0; i < 26; i++) {
                key += std::to_string(char_count[i]) + ',';
            }
            groups[key].push_back(s);
        }

        std::vector<vector<string>> out;
        for (auto m : groups) out.push_back(m.second);
        return out;
    }
};
