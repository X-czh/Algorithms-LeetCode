# 279-Perfect Squares

## Approach: Dynamic Programming

Recursive structure:

* numSquares(0) = 0
* numSquares(n) = min(numSquares(n-k) + 1 for any square number k)

Time complexity: O(n x sqrt(n)).

Space complexity: O(n).

```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp[0] = 0;
        
        // precalculate the square numbers
        vector<int> square_nums{0};
        for (int i = 1; i * i <= n; i++) {
            square_nums.push_back(i * i);
        }
        
        for (int i = 0; i <= n; i++) {
            for (int s = 1; s * s <= n; s++) {
                if (i >= square_nums[s]) {
                    dp[i] = min(dp[i], dp[i - square_nums[s]] + 1);
                }
            }
        }
        return dp[n];
    }
};
```
