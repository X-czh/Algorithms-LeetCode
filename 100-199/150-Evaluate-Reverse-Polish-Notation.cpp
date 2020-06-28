// Use a stack. Stack only holds numbers, when an operator is encountered,
// pop two oprands, apply operation, and push reduced result back to stack.

// Time complexity: O(n).
// Space complexity: O(n).

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int oprand2 = s.top(); s.pop();
                int oprand1 = s.top(); s.pop();

                if (token == "+")
                    s.push(oprand1 + oprand2);
                else if (token == "-")
                    s.push(oprand1 - oprand2);
                else if (token == "*")
                    s.push(oprand1 * oprand2);
                else
                    s.push(oprand1 / oprand2);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
