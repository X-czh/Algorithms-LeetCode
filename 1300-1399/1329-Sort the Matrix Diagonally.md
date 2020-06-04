# 1329-Sort the Matrix Diagonally

[Problem](https://leetcode.com/problems/sort-the-matrix-diagonally/)

## Approach

All cells in the same diagonal (i,j) have the same difference so we can get the diagonal of a cell using the difference i-j.

Time complexity: O(M \* N \* log(M + N)).

Space complexity: O(M * N) extra space.

```c++
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int M = mat.size();
        if (M == 0) return {};
        const int N = mat[0].size();
        if (N == 0) return {};

        unordered_map<int, priority_queue<int, vector<int>, std::greater<int>>> m;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                m[i-j].push(mat[i][j]);
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = m[i-j].top();
                m[i-j].pop();
            }
        }

        return mat;
    }
};
```

A slightly more efficient solution using vector instead of hash map at the cost of more complex index computation:

```c++
class Solution2 {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int M = mat.size();
        if (M == 0) return {};
        const int N = mat[0].size();
        if (N == 0) return {};

        vector<priority_queue<int, vector<int>, std::greater<int>>> v(M + N - 1);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                v[i-j + N-1].push(mat[i][j]);
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                mat[i][j] = v[i-j + N-1].top();
                v[i-j + N-1].pop();
            }
        }

        return mat;
    }
};
```
