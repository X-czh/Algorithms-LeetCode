# 044-Wildcard Matching

[Problem](https://leetcode.com/problems/wildcard-matching/)

## Approach 1: Dynamic Programming

Similar to 072-Edit Distance, recurrence structure to match str[1..i] by pat[1..j]:

1. Matching specific element (if str[i] = pat[j]): matching(i, j) = matching(i - 1, j - 1),

2. Matching any single character (pat[j] = '?'): matching(i, j) = matching(i - 1, j - 1),

3. Matching any sequence of characters (pat[j] = '*'): matching(i, j) = matching(i - 1, j) (matches at least one char) OR matching(i, j - 1) (matches empty).

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
            if (p[j - 1] == '*') {
                matches[0][j] = matches[0][j - 1];
            }
        }

        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    matches[i][j] = matches[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    matches[i][j] = matches[i - 1][j] ||    // * matches at least one char
                                    matches[i][j - 1];      // * matches empty
                }
            }
        }

        return matches[M][N];
    }
};
```
