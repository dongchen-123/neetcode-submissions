class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num_stack;
        int a, b, c;
        for (const auto& t : tokens) {
            if (t != "+" && t != "-" && t != "*" && t != "/") num_stack.push(stoi(t));
            else {
                a = num_stack.top();
                num_stack.pop();
                b = num_stack.top();
                num_stack.pop();
                if (t == "+") c = a + b;
                else if (t == "-") c = b - a;
                else if (t == "*") c = b * a;
                else if (t == "/") c = b / a;
                else c = 0;
                num_stack.push(c);
            }
        }
        return num_stack.top();
    }
};
