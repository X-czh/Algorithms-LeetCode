# 121-Best Time to Buy and Sell Stock

[Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

## Algorithm

We just need to find the largest peak following the smallest valley.

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
