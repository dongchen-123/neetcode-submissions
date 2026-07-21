class Solution {
public:
    bool isPalindrome(string s) {
        std::string clean_s = "";
        for (const auto& c : s) {
            if (isalnum(c)) clean_s += (char)tolower(c);
        }
         int left = 0;
        int right = clean_s.size() - 1;
        while (left < right) {
            if (clean_s[left] == clean_s[right]) {
                left ++;
                right --;
            }
            else return false;
        }
        return true;
        
    }
};
