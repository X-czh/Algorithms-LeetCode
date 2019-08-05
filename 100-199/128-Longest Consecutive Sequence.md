# 128-Longest Consecutive Sequence

[Problem](https://leetcode.com/problems/longest-consecutive-sequence/)

## Approach 1: Sorting

One pitall is that we shall overpass the consecutive identical numbers.

Time complexity: O(nlogn).

Space complexity: O(1) (in-place) or O(n) (modification prohibited).

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int max_len = 1;
        int curr_len = 1;
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ++curr_len;
            } else if (nums[i] > nums[i - 1] + 1) {
                max_len = max(max_len, curr_len);
                curr_len = 1;
            }
        }
        max_len = max(max_len, curr_len);
        return max_len;
    }
};
```

## Approach 2: Hash Set

We only attempt to build sequences from numbers that are not already part of a longer sequence. With the help of O(1) look-up of hash set, we can reach O(n) time complexity.

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }

        int max_len = 1;

        for (auto num : s) {
            if (s.find(num - 1) == s.end()) {
                int curr_num = num;
                int curr_len = 1;

                while (s.find(curr_num + 1) != s.end()) {
                    ++curr_num;
                    ++curr_len;
                }

                max_len = max(max_len, curr_len);
            }
        }

        return max_len;
    }
};
```
