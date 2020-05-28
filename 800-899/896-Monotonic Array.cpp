// Time complexity: O(n).
// Space complexity: O(1) extra space.

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size();

        if (len <= 1) {
            return true;
        }
        
        if (A[0] <= A[len - 1]) {
            for (int i = 0; i < len - 1; i++) {
                if (A[i] > A[i + 1]) {
                    return false;
                }
            }
        } else {
            for (int i = 0; i < len - 1; i++) {
                if (A[i] < A[i + 1]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
