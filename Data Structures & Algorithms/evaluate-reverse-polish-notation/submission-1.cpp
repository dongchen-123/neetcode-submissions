class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> n_stack;
        for (const auto& t : tokens) {
            if (t != "+" && t != "-" && t!= "*" && t != "/") n_stack.push(std::stoi(t));
            else {
                int a = n_stack.top();
                n_stack.pop();
                int b = n_stack.top();
                n_stack.pop();
                int c;
                if (t == "+") c = b + a;
                if (t == "-") c = b - a;
                if (t == "*") c = b * a;
                if (t == "/") c = b / a;
                n_stack.push(c);
            }
        }
        return n_stack.top();
    }
};
