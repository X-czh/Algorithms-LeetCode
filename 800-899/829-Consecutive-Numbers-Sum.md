# 829 Consecutive Numbers Sum

[Problem](https://leetcode.com/problems/consecutive-numbers-sum/)

## Solution

We can write N = (x+1) + (x+2) + ... + (x+k), x >= 0, k >= 1, both integers. It can be further written as N - (1 + 2 + ... + k) = k * x, and as long as N - (1 + 2 + ... + k) is evenly divided by k, there exist a solution x.

Time complexity: O(sqrt(n)).

Space complexity: O(1).

```c++
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int cnt = 0;

        for (int k = 1; ; k++) {
            N -= k;
            if (N < 0) break;
            if (N % k == 0) cnt++;
        }

        return cnt;
    }
};
```
