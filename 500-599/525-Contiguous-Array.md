# 525-Contiguous Array

[Problem](https://leetcode.com/problems/contiguous-array/)

## Approach 1: Brute Force

Time complexity: O(n^2).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int N = nums.size();
        
        int max_len = 0;
        for (int i = 0; i < N; i++) {
            int cnt_zero = 0;
            int cnt_one = 0;
            for (int j = i; j < N; j++) {
                if (nums[j] == 0)
                    cnt_zero++;
                else
                    cnt_one++;
                if (cnt_zero == cnt_one)
                    max_len = max(max_len, j - i + 1);
            }
        }
        return max_len;
    }
};
```

## Approach 2: Hash Map

__*Intuition*__: record the difference between cnt_ones and cnt_zeros at each position (start counting from the beginning of the array), if there are two positions with the same count difference, then the subarray (right inclusive, left exclusive) between the two have equal number of ones and zeros.

__*Algorithm*__: use a hashmap to store the difference between cnt_ones and cnt_zeros and the __first__ position this difference value occurs. Iterate through the array once, at each position, compute the difference between cnt_ones and cnt_zeros, check if the differece value already occurs before, if no add it to the hashmap, if yes, compute the subarray size and update max length.

Time complexity: O(n).

Space complexity: O(n) extra space.

```c++
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m_diff;
        m_diff.insert({0, -1});
        
        int max_len = 0;
        int ones = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones += nums[i];
            int diff = 2 * ones - (i + 1); // ones - zeros
            if (m_diff.find(diff) == m_diff.end()) {
                m_diff[diff] = i;
            } else {
                max_len = max(max_len, i - m_diff[diff]);
            }
        }
        return max_len;
    }
};
```