# 097-Interleaving String

[Problem](https://leetcode.com/problems/interleaving-string/)

## Approach 1: Dynamic Programming

Similar to 072-Edit Distance, recurrence structure to see whether s3[1..(i + j)] can be formed by the interleaving of s1[1..i] and s2[1..j]:

If s1[i] != s2[j]:

* if s3[i + j] = s1[i]: interleaves(i, j) = interleaves(i - 1, j),

* if s3[i + j] = s2[j]: interleaves(i, j) = interleaves(i, j - 1).

If s1[i] == s2[j]:

* if s3[i + j] = s1[i]: interleaves(i, j) = interleaves(i - 1, j) OR interleaves(i, j - 1).

We then apply dynamic programming for smarter recursion.

Time complexity: O(L * M).

Space complexity: O(L * M).

```c++
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        const int L = s1.size();
        const int M = s2.size();
        const int N = s3.size();
        if (L + M != N) return false;

        vector<vector<bool>> interleaves(L + 1, vector<bool>(M + 1, false));

        interleaves[0][0] = true;
        for (int i = 1; i <= L; ++i) {
            if (s3[i - 1] == s1[i - 1]) {
                interleaves[i][0] = interleaves[i - 1][0];
            }
        }
        for (int j = 1; j <= M; ++j) {
            if (s3[j - 1] == s2[j - 1]) {
                interleaves[0][j] = interleaves[0][j - 1];
            }
        }

        for (int i = 1; i <= L; ++i) {
            for (int j = 1; j <= M; ++j) {
                if (s3[i + j - 1] == s1[i - 1]) {
                    interleaves[i][j] = interleaves[i][j] || interleaves[i - 1][j];
                }
                if (s3[i + j - 1] == s2[j - 1]) {
                    interleaves[i][j] = interleaves[i][j] || interleaves[i][j - 1];
                }
            }
        }

        return interleaves[L][M];
    }
};
```
