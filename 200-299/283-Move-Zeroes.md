# 283-Move Zeroes

[Problem](https://leetcode.com/problems/move-zeroes/)

## Approach 1

Invariants maintained:

* All elements before the slow pointer (left) are non-zeroes.
* All elements between the current (right) and slow pointer are zeroes.

Time complexity: O(n^2).

Space complexity: O(1).

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        const int n = nums.size();

        int left{0};
        int right{0};

        while (right < n) {
            while (left < n && nums[left] != 0) {
                left++;
            }
            right = left;
            while (right < n && nums[right] == 0) {
                right++;
            }
            if (left != right && right < n) {
                swap(nums[left], nums[right]);
            }
        }
    }
};
```

## Approach 2: Optimized

Same invariants maintained.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
```
