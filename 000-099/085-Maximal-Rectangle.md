# 085-Maximal Rectangle

[Problem](https://leetcode.com/problems/maximal-rectangle/)

## Approach 1: Brute Force

Time complexity: O(m * n^2).

Space complexity: O(m * n).

```c++
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int height = matrix.size();
        int width = matrix[0].size();

        vector<vector<int>> num_left_ones(height, vector<int>(width, 0));
        for (auto i = 0; i < height; ++i) {
            if (matrix[i][0] == '1') {
                num_left_ones[i][0] = 1;
            }
            for (auto j = 1; j < width; ++j) {
                if (matrix[i][j] == '1') {
                    num_left_ones[i][j] = num_left_ones[i][j - 1] + 1;
                }
            }
        }

        int max_area = 0;
        for (auto j = 0; j < width; ++j) {
            for (auto i_top = 0; i_top < height; ++i_top) {
                int min_left_ones = width;
                for (auto i_bottom = i_top; i_bottom < height; ++i_bottom) {
                    min_left_ones = min(num_left_ones[i_bottom][j], min_left_ones);
                    int area = min_left_ones * (i_bottom - i_top + 1);
                    max_area = max(area, max_area);
                }
            }
        }

        return max_area;
    }
};
```
