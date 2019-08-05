# 073-Set Matrix Zeroes

[Problem](https://leetcode.com/problems/set-matrix-zeroes/)

## Approach 1: Additional Memory Approach

Use two lists to record the rows and coloums that contain zero.

Time complexity: O(m * n).

Space complexity: O(m + n).

```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        auto m = matrix.size();
        auto n = matrix[0].size();
        vector<int> zero_row(m, 0);
        vector<int> zero_col(n, 0);

        for (auto i = 0; i < m; ++i) {
            for (auto j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    zero_row[i] = 1;
                    zero_col[j] = 1;
                }
            }
        }

        for (auto i = 0; i < m; ++i) {
            if (zero_row[i] == 1) {
                for (auto j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (auto j = 0; j < n; ++j) {
            if (zero_col[j] == 1) {
                for (auto i = 0; i < m; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
```

## Approach 2: O(1) Space

Instead of using additional memory, we can use the first row and first column to record the rows and coloums that contain zero. As the first cell for both first row and first column is the same, we can use an additional variable for storing whether the first row or column contains zero.

Time complexity: O(m * n).

Space complexity: O(1).

```c++
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col_zero = false;
        auto m = matrix.size();
        auto n = matrix[0].size();

        for (auto i = 0; i < m; ++i) {

            // first cell for both first row and first column is the same
            // use additional variable for first column
            if (matrix[i][0] == 0) {
                col_zero = true;
            }

            // if an element is zero, set the first element of the
            // corresponding row and column to 0
            for (auto j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // iterate over the array, use the first row and first column
        // to update the elements
        for (auto i = 1; i < m; ++i) {
            for (auto j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // see if the first row needs to be set to zero as well
        if (matrix[0][0] == 0) {
            for (auto j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        // see if the first column needs to be set to zero as well
        if (col_zero == true) {
            for (auto i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
```
