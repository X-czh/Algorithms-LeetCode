# 188-Best Time to Buy and Sell Stock IV

[Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)

At most k transactions.

## Approach 1: Dynamic Programming

This is an extension from 123-Best Time to Buy and Sell Stock II, Approach 2.

Time complexity: O(n * k).

Space complexity: O(k).

```c++
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int N = prices.size();
        if (k == 0 || N <= 1) return 0;
        k = min(k, N / 2);

        vector<int> buys(k, prices.front());
        vector<int> buy_and_sells(k, 0);

        for (int price : prices) {
            buys[0] = min(buys[0], price);
            buy_and_sells[0] = max(buy_and_sells[0], price - buys[0]);
            for (int i = 1; i < k; ++i) {
                buys[i] = min(buys[i], price - buy_and_sells[i - 1]);
                buy_and_sells[i] = max(buy_and_sells[i], price - buys[i]);
            }
        }

        return buy_and_sells.back();
    }
};
```
