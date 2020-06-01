// Time complexity: O(num1.length + num2.length).
// Space complexity: O(1) auxiliary space.

class Solution1 {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int m = num1.size() - 1;
        int n = num2.size() - 1;
        int carry = 0;;
        
        while (m >= 0 || n >= 0) {
            int p = (m >= 0) ? num1[m--] - '0' : 0;
            int q = (n >= 0) ? num2[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }
        return (carry > 0) ? to_string(carry) + res : res;
    }
};

// A faster version using std::reverse
// String prepend is expensive, use string append instead, and reverse in the end
//  String.push_back: Amortized constant.
//  std::reverse: Exactly (last - first)/2 swaps.
class Solution2 {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int m = num1.size() - 1;
        int n = num2.size() - 1;
        int carry = 0;
        
        while (m >= 0 || n >= 0) {
            int p = (m >= 0) ? num1[m--] - '0' : 0;
            int q = (n >= 0) ? num2[n--] - '0' : 0;
            int sum = p + q + carry;
            res.push_back('0' + sum % 10);
            carry = sum / 10;
        }

        if (carry > 0)
            res.push_back('0' + carry);
        
        std::reverse(res.begin(), res.end());
        return res;
    }
};
