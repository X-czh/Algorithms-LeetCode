# 121-Best Time to Buy and Sell Stock

[Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

At most one transaction.

## Approach: Greedy

We just try to buy at the lowest price, and sell at the highest price afterwards.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit{0};
        int min_price{numeric_limits<int>::max()};
        int max_price{numeric_limits<int>::min()};

        for (auto price : prices) {
            // reset buy in date && sold out date
            if (price < min_price) {
                min_price = price;
                max_price = price;
            }
            // reset sold out date
            if (price > max_price) {
                max_price = price;
                int profit{max_price - min_price};
                if (profit > max_profit) max_profit = profit;
            }
        }

        return max_profit;
    }
};
```

## Approach 2: Another Formulation

Let max_profit[i] be the max_profit you can get if you choose to buy on day i, and suffix_max[i] be the highest price since day i (inclusive). Then max_profit[i] = suffix_max[i + 1] - prices[i].

### First thought: DP for suffix_max

Time complexity: O(n).

Space complexity: O(n).

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int max_profit = 0;
        vector<int> suffix_max(prices.size(), prices.back());
        for (int i = prices.size() - 2; i >= 0; i--) {
            max_profit = max(max_profit, suffix_max[i + 1] - prices[i]);
            suffix_max[i] = max(suffix_max[i + 1], prices[i]);
        }

        return max_profit;
    }
};
```

### Improvement

Time complexity: O(n).

Space complexity: O(1).

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int max_profit = 0;
        int suffix_max = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            max_profit = max(max_profit, suffix_max - prices[i]);
            suffix_max = max(suffix_max, prices[i]);
        }

        return max_profit;
    }
};
```
