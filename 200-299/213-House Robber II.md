# 213-House Robber II

[Problem](https://leetcode.com/problems/house-robber-ii/)

## Approach: Dynamic Programming

The only extra complexity compared to 198-House Robber lies in the adjacancy of the first and last house. The straight-forward way is to consider robbing the first house and not robbing the first house seperately.

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        const auto N = nums.size();
        if (N == 0) return 0;
        if (N == 1) return nums[0];

        vector<int> mem(N, 0);

        // rob the first house
        mem[0] = nums[0];
        mem[1] = nums[0];
        for (auto i = 2; i < N - 1; ++i) {
            mem[i] = max(mem[i - 1], mem[i - 2] + nums[i]);
        }
        int max_amount_1 = *max_element(mem.begin(), mem.end());

        // do not rob the first house
        mem[0] = 0;
        mem[1] = nums[1];
        for (auto i = 2; i < N; ++i) {
            mem[i] = max(mem[i - 1], mem[i - 2] + nums[i]);
        }
        int max_amount_2 = *max_element(mem.begin(), mem.end());

        return max(max_amount_1, max_amount_2);
    }
};
```
