# 198-House Robber

[Problem](https://leetcode.com/problems/house-robber/)

## Approach 1: Dynamic Programming

Let mem[i] represent the optimal amount robbed in the first i houses. mem[i + 1] = max(mem[j] + nums[i]) for j < i.

Time complexity: O(n^2).

Space complexity: O(n).

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        auto N = nums.size();
        if (N == 0) return 0;

        vector<int> mem(nums, 0);
        for (auto i = 0; i < N; ++i) {
            for (auto j = 0; j < i - 1; ++j) {
                int amount = mem[j] + nums[i];
                if (amount > mem[i]) {
                    mem[i] = amount;
                }
            }
        }

        return *max_element(mem.begin(), mem.end());
    }
};
```

## Approach 2: Optimized Dynamic Programming

Let mem[i] represent the optimal amount robbed in the first i houses.

*Base case*: mem[0] = nums[0], mem[1] = max(nums[0], nums[1]).

*State transition*:

* if mem[i - 1] == mem[i - 2], then the (i - 1)-th house is not robbed with the optimal policy of robbing the first (i - 1) houses, mem[i] = mem[i - 1] + nums[i];

* if mem[i - 1] != mem[i - 2], then the (i - 1)-th house is robbed with the optimal policy of robbing the first (i - 1) houses, mem[i] = max(mem[i - 2] + nums[i], mem[i - 1]), aka, we decide if we would like to take the optimal policy of robbing the first (i - 1) houses and leave the i-th house unrobbed, or take the optimal policy of robbing the first (i - 2) houses and rob the i-th house.

*Optimized State transition*:
Note that the above two state transition functions can be merged into one: mem[i] = max(mem[i - 1], mem[i - 2] + nums[i]).

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution1 {
public:
    int rob(vector<int>& nums) {
        auto N = nums.size();
        if (N == 0) return 0;
        if (N == 1) return nums[0];

        vector<int> mem(N);
        mem[0] = nums[0];
        mem[1] = max(nums[0], nums[1]);
        for (auto i = 2; i < N; ++i) {
            if (mem[i - 1] == mem[i - 2]) { // (i - 1)-th house is not robbed in the optimal case of (i - 1) houses
                mem[i] = mem[i - 1] + nums[i];
            } else { // (i - 1)-th house is robbed in the optimal case of (i - 1) houses
                int amount = mem[i - 2] + nums[i];
                mem[i] = (amount > mem[i - 1]) ? amount : mem[i - 1];
            }
        }

        return *max_element(mem.begin(), mem.end());
    }
};

// optimized
class Solution2 {
public:
    int rob(vector<int>& nums) {
        auto N = nums.size();
        if (N == 0) return 0;
        if (N == 1) return nums[0];

        vector<int> mem(N);
        mem[0] = nums[0];
        mem[1] = max(nums[0], nums[1]);
        for (auto i = 2; i < N; ++i) {
            mem[i] = max(mem[i - 1], mem[i - 2] + nums[i]);
        }

        return *max_element(mem.begin(), mem.end());
    }
};
```

Further optimized: O(n) time, O(1) space.

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev_max = 0;
        int curr_max = 0;
        for (int x : nums) {
            int temp = curr_max;
            curr_max = max(prev_max + x, curr_max);
            prev_max = temp;
        }
        return curr_max;
    }
};
```
