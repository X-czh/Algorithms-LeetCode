# 923-3Sum With Multiplicity

[Problem](https://leetcode.com/problems/3sum-with-multiplicity/)

## Approach 1: 3-Sum Variant

Time complexity: O(n^2).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        const int N = A.size();
        if (N < 3)
            return 0;

        int ans = 0;
        const int modulo = 1000000000 + 7;
        sort(A.begin(), A.end());

        for (int i = 0; i < N - 2; i++) {
            int left = i + 1;
            int right = N - 1;
            while (left < right) {
                int sum = A[i] + A[left] + A[right];
                if (sum == target) {
                    int left_cnt = 1;
                    while (left < right && A[left + 1] == A[left]) {
                        left++;
                        left_cnt++;
                    }
                    int right_cnt = 1;
                    while (left < right && A[right - 1] == A[right]) {
                        right--;
                        right_cnt++;
                    }
                    if (A[left] == A[right])
                        ans += left_cnt * (left_cnt - 1) / 2; // C(n, k)
                    else
                        ans += left_cnt * right_cnt;
                    ans %= modulo;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return ans;
    }
};
```
