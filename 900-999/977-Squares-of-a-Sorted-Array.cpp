// Two pointer
// Time complexity: O(n).
// Space complexity: O(1) extra space.

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int N = (int)A.size();
        int i = 0; // to iterate non-negative numbers
        while (i < N && A[i] < 0) i++;
        int j = i - 1; // to iterate negative numbers reversely
        
        vector<int> ans;
        auto sqr = [](int x) { return x * x; };

        while (i < N && j >= 0) {
            if (sqr(A[i]) < sqr(A[j])) {
                ans.push_back(sqr(A[i]));
                i++;
            } else {
                ans.push_back(sqr(A[j]));
                j--;
            }
        }
        while (i < N) {
            ans.push_back(sqr(A[i]));
            i++;
        }
        while (j >= 0) {
            ans.push_back(sqr(A[j]));
            j--;
        }

        return ans;
    }
};
