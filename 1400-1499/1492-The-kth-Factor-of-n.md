# 1492-The kth Factor of n

[Problem](https://leetcode.com/problems/the-kth-factor-of-n/)

## Appraoch 1

This is my solution during the contest. It makes use of the symmetry of divisors to achieve O(sqrt(n)) time.

Time complexity: O(sqrt(n)).

Space complexity: O(sqrt(n)).

```c++
class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> lst;
        int sqr_root = sqrt(n);
        int idx = 0;
        for (int i = 1; i <= sqr_root; i++) {
            if (n % i == 0) {
                lst.push_back(i);
                idx++;
                if (idx == k) {
                    return i;
                }
            }
        }
        if (n == sqr_root * sqr_root) {
            if (k > idx * 2 - 1)
                return -1;
            return n / lst[idx - 1 - (k - idx)];
        } else {
            if (k > idx * 2)
                return -1;
            return n / lst[idx - (k - idx)];
        }
    }
};
```

## Approach 2

Just check the divisibility and count; note that we only go till n / 2. In the end, if k == 1, then the last divisor is our number n itself.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    int kthFactor(int n, int k) {
        for (int d = 1; d <= n / 2; ++d)
            if (n % d == 0 && --k == 0)
                return d;
        return k == 1 ? n : -1;
    }
};
```
