# 115-Distinct Subsequences 

[Problem](https://leetcode.com/problems/distinct-subsequences/)

## Approach 1: Dynamic Programming

Similar to 072-Edit Distance, recurrence structure to count s[1..i] as subsequences of t[1..j]:

1. s[i] = t[j]: num_distincts(i, j) = num_distincts(i, j - 1) (do not use t[j] to match s[i]) + num_distincts(i - 1, j - 1) (use t[j] to match s[i]),

2. s[i] != t[j]: num_distincts(i, j) = num_distincts(i, j - 1) (t[j] is redundant).

We then apply dynamic programming for smarter recursion.

Time complexity: O(M * N).

Space complexity: O(M * N).

```c++
class Solution {
public:
    int numDistinct(string s, string t) {
        const int M = t.size();
        const int N = s.size();
        if (N < M) return 0;

        vector<vector<long>> num_distincts(M + 1, vector<long>(N + 1, 0));

        for (int j = 0; j <= N; ++j) {
            num_distincts[0][j] = 1;
        }

        for (int i = 1; i <= M; ++i) {
            for (int j = i; j <= N; ++j) {
                int indicator = (t[i - 1] == s[j - 1]) ? 1 : 0;
                num_distincts[i][j] = num_distincts[i - 1][j - 1] * indicator + 
                    num_distincts[i][j - 1];
            }
        }

        return num_distincts[M][N];
    }
};
```
