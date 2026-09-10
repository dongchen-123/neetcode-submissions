class Solution {
public:
    bool isValid(string s) {
        std::stack<char> paren_stack;
        if (s.length() == 1) return false;
        for (const auto& p:s) {
            if (p == '(' || p == '{' || p == '[') {
                paren_stack.push(p);
            }
            else {
                if (paren_stack.empty()) return false;
                else if ((paren_stack.top() == '(' && p == ')') ||
                    (paren_stack.top() == '[' && p == ']') ||
                    (paren_stack.top() == '{' && p == '}')) paren_stack.pop();
                else return false;
            }
        }
        if (paren_stack.empty()) return true;
        else return false;
        
    }
};
