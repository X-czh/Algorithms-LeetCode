# 1143-Longest Common Subsequence

[Problem](https://leetcode.com/problems/longest-common-subsequence/)

## Approach: Dynamic Programming

Time Complexity: O(len(text1) * len(text2)).

Space complexity: O(len(text1) * len(text2)).

**Base Case:**

LCS(i, j) = 0, if i = 0 or j = 0

**Recursive structure:**

LCS(i, j) =

* LCS(i - 1, j - 1) + 1, if text1[i] = text2[j]

* max(LCS(i - 1, j), LCS(i, j - 1)), if text1[i] != text2[j]

```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int len1 = text1.size();
        const int len2 = text2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i < len1 + 1; i++) {
            for (int j = 1; j < len2 + 1; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
```
