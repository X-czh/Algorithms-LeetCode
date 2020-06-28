# 072-Edit Distance

[Problem](https://leetcode.com/problems/edit-distance/)

## Approach 1: Dynamic Programming

Assume a word w1 has been transformed to another word w2 except for the last operation unperformed at the end of w1. There are three elementary operations available: inserting a new char, deleting an existing char and replacing an existing char. Based on this observation, we have the following recurrence structure to transform w1[1..i] to w2[1..j]:

1. Edit by insertion: ins = edit_distance(i, j - 1) + 1,

2. Edit by deletion: del = edit_distance(i - 1, j) + 1,

3. Edit by replacement: rep = edit_distance(i - 1, j - 1) if w1[i] = w2[j] otherwise edit_distance(i - 1, j - 1) + 1,

and edit_distance(i, j) = min(ins, del, rep).

We then apply dynamic programming for smarter recursion.

Time complexity: O(M * N).

Space complexity: O(M * N).

```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int M = word1.size();
        const int N = word2.size();

        vector<vector<int>> edit_distance(M + 1, vector<int>(N + 1, 0));

        for (int j = 0; j <= N; ++j) {
            edit_distance[0][j] = j;
        }

        for (int i = 1; i <= M; ++i) {
            edit_distance[i][0] = i;
            for (int j = 1; j <= N; ++j) {
                int ins, del, rep;
                ins = edit_distance[i][j - 1] + 1;
                del = edit_distance[i - 1][j] + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    rep = edit_distance[i - 1][j - 1];
                } else {
                    rep = edit_distance[i - 1][j - 1] + 1;
                }
                edit_distance[i][j] = min({ins, del, rep});
            }
        }

        return edit_distance[M][N];
    }
};
```
