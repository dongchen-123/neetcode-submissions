class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map <char, int> s_map, t_map;
        for (const auto& c : s) s_map[c] ++;
        for (const auto& c : t) t_map[c] ++;
        return (s_map == t_map);
    }
};
