// Sort + Two Pointers
// Time complexity: O(nlogn).
// Space complexity: O(1) extra space.

class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        if (A.size() < 2) return -1;

        sort(A.begin(), A.end());
        
        int S = A[0] + A[1];
        if (S >= K) return -1;

        int left = 0;
        int right = A.size() - 1;
        while (left < right) {
            int sum = A[left] + A[right];
            if (sum < K) {
                S = max(S, sum);
                left++;
            } else {
                right--;
            }
        }
        return S;
    }
};
