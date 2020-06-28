# 123-Best Time to Buy and Sell Stock III

[Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

At most 2 transactions.

## Approach 1: Dynamic Programming

Let max_first_transaction_profits[i] denote the max first transaction profit you can make from the first day to the i-th day. Let max_second_transaction_profits[i] denote the max second transaction profit you can make from the i-th day to the last day. Let max_profit[i] denote the max profit you can make by making the first transaction on or before the i-th day.

Recurrence structure:

* max_profit[0] = 0,
* max_profit[i] = max(max_profit[i - 1], max_first_transaction_profits[i] + max_second_transaction_profits[i + 1]) (0 < i < N),
* max_profit[N] = max(max_profit[N - 1], max_first_transaction_profits[N]).

For max_first_transaction_profits and max_second_transaction_profits, we can also find recurrence structures in them.

We then apply dynamic programming for smarter recursion.

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int N = prices.size();
        if (N <= 1) return 0;

        // i-th number is the max first transaction profit
        // from the first day to the i-th day
        vector<int> max_first_transaction_profits(N, 0);

        // i-th number is the max second transaction profit
        // from the i-th day to the last day
        vector<int> max_second_transaction_profits(N, 0);

        // update max_first_transaction_profits
        int min_price = prices.front();
        for (int i = 1; i < N; ++i) {
            max_first_transaction_profits[i] = max(
                max_first_transaction_profits[i - 1],
                prices[i] - min_price);
            min_price = min(min_price, prices[i]);
        }

        // update max_second_transaction_profits
        int max_price = prices.back();
        for (int i = N - 2; i >= 0; --i) {
            max_second_transaction_profits[i] = max(
                max_second_transaction_profits[i + 1],
                max_price - prices[i]);
            max_price = max(max_price, prices[i]);
        }

        // update max_profit
        int max_profit = 0;
        for (int i = 0; i < N - 1; ++i) {
            max_profit = max(max_profit, max_first_transaction_profits[i] + max_second_transaction_profits[i + 1]);
        }
        // don't do second transaction
        max_profit = max(max_profit, max_first_transaction_profits.back());

        return max_profit;
    }
};
```

## Approach 2: Greedy

The intuition is that we can consider the problem as a game, and we as agent could make at most two transactions in order to gain the maximum points (profits) from the game. The two transactions be decomposed into 4 actions: "buy of transaction #1", "sell of transaction #1", "buy of transaction #2" and "sell of transaction #2". To solve the game, we simply run a simulation along the sequence of prices, at each time step, we calculate the potential outcomes for each of our actions. At the end of the simulation, the outcome of the final action "sell of transaction #2" would be the desired output of the problem.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t1_cost = numeric_limits<int>::max();
        int t2_cost = numeric_limits<int>::max();
        int t1_profit = 0;
        int t2_profit = 0;

        for (int price : prices) {
            t1_cost = min(t1_cost, price);
            t1_profit = max(t1_profit, price - t1_cost);
            t2_cost = min(t2_cost, price - t1_profit);
            t2_profit = max(t2_profit, price - t2_cost);
        }

        return t2_profit;
    }
};
```
