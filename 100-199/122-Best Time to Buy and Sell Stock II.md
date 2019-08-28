# 122-Best Time to Buy and Sell Stock II

[Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## Approach: Greedy

The maximum profit is obtained by buying in at each valley and selling out at the peak right after it. It is also equivalent to buy in whenever the price raises the next day, and sold out right the next day.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit{0};
        for (int i{0}; i < static_cast<int>(prices.size()) - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                profit += prices[i + 1] - prices[i];
            }
        }
        return profit;
    }
};
```

## Trap: vector.size() is unsigned!

A trap lies in that vector.size() is an unsigned int. When we are trying to substract from it, we have to take care that the result won't be negative, otherwise we have to cast it to int first, like what I did in the code above. To avoid casting, we can start iterating from index 1, like the code below.

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit{0};
        for (int i{1}; i < prices.size(); ++i) {
            if (prices[i] < prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
```
