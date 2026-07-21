class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map < std::vector<int>, std::vector<std::string> > a_map;
        for (const auto& s : strs) {
            std::vector<int> alphabet_cnt;
            alphabet_cnt.assign(26,0);
            for (const auto& c : s) alphabet_cnt[c - 'a'] ++;
            a_map[alphabet_cnt].push_back(s);
        }
        std::vector<std::vector<string>> out;
        for (const auto& m : a_map) out.push_back(m.second);
        return out;
    }
};
