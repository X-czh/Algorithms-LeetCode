# 091-Decode Ways

[Problem](https://leetcode.com/problems/decode-ways/)

## Approach

Let the given string be SS, a list of chars. When len(SS) >= 2, we can write SS = S ::: x :: y :: Nil, where ::: means concatenation of two lists and :: means concatenation of an element and a list. f(SS) = f(S) \* I(x :: y :: Nil) + f(S ::: x :: Nil) \* I(y :: Nil), where I is a function that maps to 0/1, indicating whether the pattern is valid or not.

### Recursive

(Similar to Fibonacci)

Time complexity: O(2^n).

Space complexity: O(2^n).

```cpp
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        return numDecodingRec(s, s.size());
    }
private:
    // precondition: !s.empty() && 0 <= end <= s.size()
    int numDecodingRec(const string& s, int end) {
        if (end == 0) {
            return 1;
        }
        if (end == 1) {
            return s[end - 1] == '0' ? 0 : 1;
        }

        // end >= 2
        if (s[end - 1] == '0') {
            if (s[end - 2] == '1' || s[end - 2] == '2') {
                return numDecodingRec(s, end - 2);
            } else {
                return 0;
            }
        }
        if (s[end - 2] == '1' || (s[end - 2] == '2' && s[end - 1] - '0' <= 6)) {
             return numDecodingRec(s, end - 1) + numDecodingRec(s, end - 2);
        }
        return numDecodingRec(s, end - 1);
    }
};
```

### Dynamic Programming

The above algorithm can be optimized using dynamic programming (memorization).

Time complexity: O(n).

Space complexity: O(n).

### Iterative

The algorithm can be further optimized. As to compute f(S ::: x :: y :: Nil), we only need to know f(S :: Nil) and f(S ::: x :: Nil), and no further values backwards, we can use two variables to store the two values, and update them iterately, leading to O(1) space complexity.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return (s[0] == '0') ? 0 : 1;

        int prev_prev_num_decodings = 1, prev_num_decodings = (s[0] == '0') ? 0 : 1;
        int num_decodings;
        for (auto i = 1; i < s.size(); ++i) {
            int code = (s[i - 1] - '0') * 10 + (s[i] - '0');
            int indicator_x = (s[i - 1] == '0') ? 0 : 1;
            int indicator_y = (s[i] == '0') ? 0 : 1;
            int indicator_xy = ((code <= 26) ? 1 : 0) * indicator_x;

            num_decodings = prev_prev_num_decodings * indicator_xy + prev_num_decodings * indicator_y;
            prev_prev_num_decodings = prev_num_decodings;
            prev_num_decodings = num_decodings;
        }

        return num_decodings;
    }
};
```
