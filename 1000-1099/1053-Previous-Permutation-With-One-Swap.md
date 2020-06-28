# 1053-Previous Permutation With One Swap

[Problem](https://leetcode.com/problems/previous-permutation-with-one-swap/)

## Approach

Idea: If the array is sorted ascendingly (i.e., descending backwardly), then there is no solution existing. Otherwise, iterate the array backwardly until you find the first non-decreasing number, and swap it with the left-most (in case of duplicates) largest number that is smaller than it on the right side.

Time complexity: O(n).

Space complexity: O(1) auxiliary space.

```c++
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int i = A.size() - 1;
        while (i >= 1 && A[i] >= A[i - 1]) i--;
        if (i == 0)
            return A;

        int j = A.size() - 1;
        while (A[i - 1] <= A[j]) j--;
        while (A[j] == A[j - 1]) j--;
        swap(A[i - 1], A[j]);
        return A;
    }
};
```
