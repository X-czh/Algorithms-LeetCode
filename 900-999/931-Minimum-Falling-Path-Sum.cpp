// Dynamic Programming
// Time complexity: O(n^2).

// In-place solution
// Space complexity: O(1) extra space.
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int ans = 0;
        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                int minPathSum = A[i-1][j];
                if (j > 0)
                    minPathSum = min(minPathSum, A[i-1][j-1]);
                if (j < A[i].size() - 1)
                    minPathSum = min(minPathSum, A[i-1][j+1]);
                A[i][j] += minPathSum;
            }
        }
        return *min_element(A.back().begin(), A.back().end());
    }
};

// Non-in-place solution
// Space complexity: O(n) extra space.
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        if (n == 1) return A[0][0];

        int ans = 0;
        vector<int> dp_prev(A[0]);
        vector<int> dp_curr(A[1]);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int minPathSum = dp_prev[j];
                if (j > 0)
                    minPathSum = min(minPathSum, dp_prev[j-1]);
                if (j < n - 1)
                    minPathSum = min(minPathSum, dp_prev[j+1]);
                dp_curr[j] = A[i][j] + minPathSum;
            }
            dp_prev.swap(dp_curr); // complexity: constant!
        }
        return *min_element(dp_prev.begin(), dp_prev.end());
    }
};
