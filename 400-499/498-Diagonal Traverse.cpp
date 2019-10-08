// Time complexity:  O(M * N).
// Space complexity: O(1) extra space.

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int M = matrix.size();
        int N = matrix[0].size();
        
        vector<int> result;
        
        int i = 0, j = 0;
        int step = 1;
        while (i < M && j < N) {
            result.push_back(matrix[i][j]);
            if (step > 0) {
                while (i - 1 >= 0 && j + 1 < N) {
                    i--;
                    j++;
                    result.push_back(matrix[i][j]);
                }
                if (j == N - 1) {
                    i++;
                } else if (i == 0) {
                    j++;
                }
            } else {
                 while (i + 1 < M && j - 1 >= 0) {
                    i++;
                    j--;
                    result.push_back(matrix[i][j]);
                }
                if (i == M - 1) {
                    j++;
                } else if (j == 0) {
                    i++;
                }
            }
            step = -step;
        }
        
        return result;
    }
};
