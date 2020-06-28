# 055-Jump Game

[Problem](https://leetcode.com/problems/jump-game/)

## Key observation

We won't get stuck if we do not encounter any zero along the way.

## Idea

Based on the key observation, we just need to check whether we can jump over the zeroes along the way.

## Solution: Greedy

Iterate through the array, maintain a variable that records the farthest position we can get to so far. Whenever we encounter a zero, check if the farthest reacheable position so far is beyond this zero. If yes, continue iterating; if no, we jump out of the loop. Finally, check whether the last position is within our reachable range.

Time complexity: O(n).

Space complexity: O(1).

C++:

```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int global_farthest_pos = 0;
        for (auto i = 0; i <= global_farthest_pos && i < nums.size(); ++i) {
            int local_farthest_pos = i + nums[i];
            if (local_farthest_pos > global_farthest_pos) {
                global_farthest_pos = local_farthest_pos;
            }
        }
        return global_farthest_pos >= nums.size() - 1;
    }
};
```

Java:

```Java
public boolean canJump(int[] nums) {
    int max_reachable = 0;
    for (int i = 0; i < nums.length; i++) {
        if (nums[i] == 0 && max_reachable == i)
            break;
        max_reachable = Math.max(i + nums[i], max_reachable);
    }
    return (max_reachable >= nums.length - 1);
}
```
