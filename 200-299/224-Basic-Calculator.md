# 224-Basic Calculator

[Problem](https://leetcode.com/problems/basic-calculator/)

## Approach 1: Two Stacks + String Reversal

Use two stacks, one for operands and one for operators, and process the given infix expression string from left to right with the following rules:

* If we come across an operand, push the operand into the operand stack.
* If we come across an an operator:
  * If the opeartor stack is empty, push the operator into the stack.
  * If the opeartor stack is not empty, compare the priority of operator on the top of the stack to the current operator, push this operator on the stack after poping all operators whose priority is greater than the current opeartor.
  * If the operator is (, just push it into the stack.
  * If the operator is ), pop the opeartors and append till we encounter matching (.
  * After processing completing string. pop all the remaining operators from stack.
* When an operator is poped from the stack, perform calculation for the top two operands of opearand stack (and pop both of them) with this operator, push the result on to the operand stack.

However, we will encounter a problem when we evaluate "1 - 2 + 1". The algorithm above will evaluate it to "1 - 3" and finally "-2". The problem is that the algorithm evaluates operators of the same priority from right to left rather than left to right, and for non-left-associate operators like "-", this will cause us trouble. A simple fix to this is to just reverse the expr string first and do the processing (also need to change the processing rule for "(" and ")" accordingly).

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;

        int num = 0;
        long base = 1;
        bool num_start = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (isdigit(c)) {
                num_start = true;
                num += base * (c - '0');
                base *= 10;
            } else {
                if (num_start) {
                    operands.push(num);
                    num_start = false;
                    num = 0;
                    base = 1;
                }
                switch (c) {
                    case '+': case '-': case ')':
                        operators.push(c);
                        break;
                    case '(':
                        while (operators.top() != ')') {
                            process(operands, operators);
                        }
                        operators.pop();
                        break;
                }
            }
        }
        if (num_start) {
            operands.push(num);
        }

        while (!operators.empty()) {
            process(operands, operators);
        }
        return operands.top();
    }
private:
    void process(stack<int>& operands, stack<char>& operators) {
        int num1 = operands.top();
        operands.pop();
        int num2 = operands.top();
        operands.pop();

        char op = operators.top();
        operators.pop();
        switch (op) {
            case '+':
                operands.push(num1 + num2);
                break;
            case '-':
                operands.push(num1 - num2);
                break;
        }
    }
};
```
