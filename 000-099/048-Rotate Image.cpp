// Transpose and Reverse
// Time complexity: O(n^2).
// Space complexity: O(1) in place.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        
        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // reserve
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};
