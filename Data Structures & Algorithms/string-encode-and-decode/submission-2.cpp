class Solution {
public:

    string encode(vector<string>& strs) {
        std::string out;
        for (const auto& word : strs) out += std::to_string(word.size())  + '#' + word;
        return out;
    }

    vector<string> decode(string s) {
        std::vector<string> out;
        int num_idx = 0;
        int len = 0;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            len = std::stoi(s.substr(i, j-i));
            out.push_back(s.substr(j+1, len));
            i = j + 1 + len;
        }
        return out;
    }
};
