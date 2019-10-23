# 673-Number of Longest Increasing Subsequence

[Problem](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

## Approach 1: Dynamic Programming

sasd

Time complexity: O(n^2).

Space complexity: O(n).

```c++
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        auto N = nums.size();
        if (N <= 1) return N;

        vector<int> mem_len(N, 1);
        vector<int> mem_num(N, 1);

        for (auto i = 1; i < N; ++i) {
            for (auto j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    auto len_seq = mem_len[j] + 1;
                    if (len_seq > mem_len[i]) {
                        mem_len[i] = len_seq;
                        mem_num[i] = mem_num[j];
                    } else if (len_seq == mem_len[i]) {
                        mem_num[i] += mem_num[j];
                    }
                }
            }
        }

        int result = 0;
        auto max_len = *max_element(mem_len.begin(), mem_len.end());
        for (auto i = 0; i < N; ++i) {
            if (mem_len[i] == max_len) {
                result += mem_num[i];
            }
        }
        return result;
    }
};
```

## Approach 2: Segment Tree

Time complexity: O(nlogn).

Space complexity: O(n).

TODO
