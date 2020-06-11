// Use normal multiplication algorithm.
// Time complexity: O(n * m).
// Space complexity: O(n + m).

class Solution {
public:
    string multiply(string num1, string num2) {
        string mul(num1.size() + num2.size(), '0');

        for (int i = num1.size() - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--) {
                int tmp = (mul[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                mul[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            mul[i] += carry;
        }

        size_t startpos = mul.find_first_not_of("0");
        if (startpos != string::npos) {
            return mul.substr(startpos);
        }
        return "0";
    }
};
