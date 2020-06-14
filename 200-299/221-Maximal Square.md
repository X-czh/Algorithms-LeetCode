# 221-Maximal Square

[Problem](https://leetcode.com/problems/maximal-square/)

## Approach 1: Brute Force

Time complexity: O((mn)^2).

Space complexity: O(1).

## Approach 2: Dynamic Programming

### Recurrence Structure

Let max_sq_len[i][j] be the max side length of the square that can be formed with its bottom-right corner be matrix[i][j].

* Base Case:
  * max_sq_len[0][0] = if matrix[0][0] == '1' then 1 else 0
  * max_sq_len[0][j] = if matrix[0][j] == '1' then max_sq_len[i][j - 1] + 1 else 0
  * max_sq_len[i][0] = if matrix[i][0] == '1' then max_sq_len[i - 1][j] + 1 else 0
* Recursive Step: max_sq_len[i][j] = if matrix[i][j] == '1' then min(max_sq_len[i - 1][j], max_sq_len[i][j - 1], max_sq_len[i - 1][j - 1]) + 1 else 0

### Complexity Analysis

Time complexity: O(mn).

Space complexity: O(mn).

```c++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int M = matrix.size();
        if (M == 0) {
            return 0;
        }
        const int N = matrix[0].size();
        if (N == 0) {
            return 0;
        }

        vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
        int max_sq_len = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    max_sq_len = max(max_sq_len, dp[i][j]);
                }
            }
        }
        return max_sq_len * max_sq_len;
    }
};
```

## Approach 3: Dynamic Programming, Space Optimized

In approach 2, we retain all the intermiediate computation results, which is not necessary. Observe that max_sq_len[i][j] only depends on max_sq_len[i - 1][j], max_sq_len[i][j - 1], max_sq_len[i - 1][j - 1]. We can merely retain the intermiediate computation results of the previous row (i - 1) as well as the prev element max_sq_len[i][j - 1] instead.

Time complexity: O(mn).

Space complexity: O(n).

```c++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int M = matrix.size();
        if (M == 0) {
            return 0;
        }
        const int N = matrix[0].size();
        if (N == 0) {
            return 0;
        }

        vector<int> dp(N + 1, 0);
        int max_sq_len = 0;
        int prev = 0;
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], dp[j]), prev) + 1;
                    max_sq_len = max(max_sq_len, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return max_sq_len * max_sq_len;
    }
};
```
