# 010-Regular Expression Matching

[Problem](https://leetcode.com/problems/regular-expression-matching/)

## Approach 1: Dynamic Programming

Similar to 072-Edit Distance, recurrence structure to match str[1..i] by reg[1..j]:

1. Matching specific element (if str[i] = reg[j]): matching(i, j) = matching(i - 1, j - 1),

2. Matching any single character (reg[j] = '.'): matching(i, j) = matching(i - 1, j - 1),

3. Matching zero or more of the preceding element (reg[j] = '*'): matching(i, j) = matching(i, j - 2) (matches zero of the preceding element) OR matching(i - 1, j) (preceding element matches str[i]).

We then apply dynamic programming for smarter recursion.

Time complexity: O(M * N).

Space complexity: O(M * N).

```c++
class Solution {
public:
    bool isMatch(string s, string p) {
        const int M = s.size();
        const int N = p.size();

        vector<vector<bool>> matches(M + 1, vector<bool>(N + 1, false));

        matches[0][0] = true;
        for (int j = 1; j <= N; ++j) {
            if (j % 2 == 0 && p[j - 1] == '*') {
                matches[0][j] = matches[0][j - 2];
            }
        }

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    matches[i][j] = matches[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    matches[i][j] =
                        ((s[i - 1] == p[j - 2] || p[j - 2] == '.')
                            && matches[i - 1][j]) || // * matches at least one char
                        matches[i][j - 2]; // * matches empty
                }
            }
        }

        return matches[M][N];
    }
};
```
