# 1493-Longest Subarray of 1's After Deleting One Element

[Problem](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)

## Approach 1: Sliding Window

Time complexity: O(n).

Space complexity: O(1) extra space.

TODO

## Approach 2

```c++
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest = 0;
        bool exist_zeros = false;
        int len_ones = 0;
        int prev_len_ones = 0;
        int prev_end_idx = -1;

        if (nums[0] == 1) {
            len_ones++;
        } else {
            exist_zeros = true;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 1) {
                len_ones++;
            } else {
                exist_zeros = true;
            }
            if (nums[i - 1] == 1 && nums[i] == 0) {
                longest = max(longest, prev_len_ones + len_ones);
                prev_len_ones = len_ones;
                prev_end_idx = i - 1;
                len_ones = 0;
            }
            if (nums[i - 1] == 0 && nums[i] == 1) {
                if (prev_end_idx >= 0 && i - prev_end_idx != 2) {
                    prev_len_ones = 0;
                    prev_end_idx = -1;
                }
            }
        }
        if (nums.size() > 1 && nums.back() == 1) {
            longest = max(longest, prev_len_ones + len_ones);
        }

        // handle the case of all 1s
        if (len_ones > 0 && !exist_zeros) {
            return len_ones - 1;
        }

        return longest;
    }
};
```
