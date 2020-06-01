// Time complexity: O(str.length)
// Space complexity: O(1) auxiliary space

class Solution {
public:
    int myAtoi(string str) {
        int idx = 0;
        long ans = 0;
        bool isPositive = true;

        // Discard leading whitespace characters.
        while (idx < str.size() && str[idx] == ' ') 
            idx++;

        // If either:
        //  1. Str is empty or it contains only whitespace characters,
        //  2. The first non-whitespace character is neither a numerical digit nor a +/- sign,
        // then no valid conversion could be performed.
        if (idx == str.size() || (!isdigit(str[idx]) && str[idx] != '+' && str[idx] != '-'))
            return 0;

        // Deal with +/- sign.
        if (str[idx] == '+') {
            idx++;
        } else if (str[idx] == '-') {
            idx++;
            isPositive = false;
        }

        // Acutal conversion.
        while (idx < str.size()) {
            char c = str[idx++];

            // Conversion stops if the next character is not a digit.
            if (!isdigit(c))
                break;

            ans = ans * 10 + (c - '0');

            // Perform boundary check.
            if (isPositive) {
                if (ans > INT_MAX)
                    return INT_MAX;
            } else {
                if (-1 * ans < INT_MIN)
                    return INT_MIN;
            }
        }

        return isPositive ? ans : -1 * ans;
    }
};
