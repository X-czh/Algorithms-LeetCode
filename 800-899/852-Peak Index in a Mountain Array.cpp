// Approach 1: Linear Scan
// Time complexity: O(n).
// Space complexity: O(1) extra space.
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i = 0;
        while (A[i] < A[i+1]) i++;
        return i;
    }
};

// Approach 2: Binary Search
// Time complexity: O(logn).
// Space complexity: O(1) extra space.
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int left = 0, right = A.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (A[mid] < A[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};
