# 045-Jump Game II

[Problem](https://leetcode.com/problems/jump-game-ii/)

## Approach 1: Dynamic Programming

mem[i] store the minimum steps required to jump from the start to position i.

State transition: mem[i] = min(mem[j] + 1) for all j such that position i can be jumped from position j.

Time complexity: O(n^2).

Space complexity: O(n).

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        vector<int> mem(nums.size(), -1);
        mem[0] = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            for (auto j = i + 1; j <= i + nums[i] && j < nums.size(); ++j) {
                if (mem[j] != -1) { // previously unreachable
                    mem[j] = min(mem[j], mem[i] + 1);
                } else {
                    mem[j] = mem[i] + 1;
                }
            }
        }

        return mem.back();
    }
};
```

## Approach 2: Greedy

Always select the position that leads to farthest jumpable position as the next step of jumping unless we can directly jump to the destination.

_Proof:_

Let G denote our greedy policy, suppose there is another policy P that leads to smaller steps of jump on a given input. G takes k steps, P takes n steps, n > k. Let G(i), P(i) denote the positions after the i-th jump following policy G and P respectively. Let f(x) denote the farthest jumpable position from position x. By the definition of the greedy policy G, f(G(i)) >= f(P(i)). Therefore, f(G(n - 1)) >= f(P(n - 1)) >= P(n). Therefore, we can already jump from G(n - 1) to P(n), the destination, leading to contradiction.

Time complexity: O(1).

Space complexity: O(1).

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        int jumps = 1;
        int start = 0; // starting idx for searching next integer to jump to
        int max_jumpable = nums[0];
        while (max_jumpable < nums.size() - 1) {
            int stop = max_jumpable; // stopping idx for searching next integer to jump to
            for (int i = start + 1; i <= stop; ++i) {
                if (i + nums[i] > max_jumpable) {
                    max_jumpable = i + nums[i];
                }
            }
            start += nums[start];
            ++jumps;
        }

        return jumps;
    }
};
```
