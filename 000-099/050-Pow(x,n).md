# 050-Pow(x, n)

[Problem](https://leetcode.com/problems/powx-n/)

## Approach 1: Brute Force Simulation

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    double myPow(double x, int n) {
        int64_t N = n; // deal with overflow
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;
        for (int64_t i = 0; i < N; i++)
            ans *= x;
        return ans;
    }
};
```

## Approach 2: Fast Power Algorithm (Exponentiation by Squaring)

Observe recurrence structure:

* Base Case: Pow(x, 0) = 1.0
* Recursive Step:
  * n even: Pow(x, n) = [Pow(x, n / 2)]^2
  * n odd: Pow(x, n) = [Pow(x, n / 2)]^2 * x

### Recursive

Time complexity: O(logn).

Space complexity: O(logn).

```c++
class Solution {
public:
    double myPow(double x, int n) {
        int64_t N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }
private:
    double fastPow(double x, int64_t n) {
        if (n == 0) {
            return 1.0;
        }

        double half = fastPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return half * half * x;
        }
    }
};
```

### Iterative

Time complexity: O(logn).

Space complexity: O(1).

```c++
class Solution {
public:
    double myPow(double x, int n) {
        int64_t N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1.0;
        double curr_pow = x;
        while (N > 0) {
            if (N % 2 == 1) {
                // Take care of the extra value that we took out
                // We will store it directly in ans
                ans *= curr_pow;
            }
            curr_pow *= curr_pow;
            N /= 2;
        }
        return ans;
    }
};
```
