# 322-Coin Change

[Problem](https://leetcode.com/problems/coin-change/)

## Approach 1: Recursion

Recurrence Structure:

* Base Case (amount = 0): F(0) = 0

* Recursive Step: min_{j=0…n−1} F(amount − coin_j) + 1 (only consider where coin_j <= amount)

Time complexity: O(S^n), where S is the amount.

Space complexity: O(n).

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty()) {
            return amount == 0 ? 0 : -1;
        }

        int min_coin = *min_element(coins.begin(), coins.end());
        return helper(coins, min_coin, amount);
    }
private:
    int helper(vector<int>& coins, int min_coin, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (amount < min_coin) {
            return -1;
        }

        int ans = numeric_limits<int>::max();
        for (auto coin : coins) {
            if (coin <= amount) {
                int tmp = helper(coins, min_coin, amount - coin);
                if (tmp == -1) {
                    return -1;
                }
                ans = min(ans, tmp + 1);
            }
        }
        return ans;
    }
};
```

## Approach 2: Dynamic Programming

Time complexity: O(S * n).

Space complexity: O(S).

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
```
