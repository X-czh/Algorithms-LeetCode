# 523-Continuous Subarray Sum

[Problem](https://leetcode.com/problems/continuous-subarray-sum/)

## Approach 1: Naive Brute Force

Time complexity: O(n^3).

Space complexity: O(1).

## Approach 2: Better Brute Force with Accumulate Array

Time complexity: O(n^2).

Space complexity: O(n) extra space.

```c++
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        assert(!nums.empty());

        vector<int> sum_acc(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            sum_acc[i] = sum_acc[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j < i - 1; j++) {
                int range_sum = sum_acc[i] - sum_acc[j];
                if ((k != 0 && range_sum % k == 0) || (k == 0 && range_sum == 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
```

## Approach 3: Hash Map

Idea: Let sum[i] be the summation from the beginning to the ith element of the array. If (sum[i] - sum[j]) % k == 0, i > j, then sum[i] % k == sum[j] % k. Therefore, we just need to traverse the array to compute sum[i], and store the sum[i] % k value. If we found that the mod value is seen before, then we know there is a contiguous subarray with its sum evenly divisible by k. Since it is required that the length of the contiguous subarray must be at least 2, we store the sum[i] % k value as well as the index i in a hash map.

Time complexity: O(n).

Space complexity: O(min(n, k)) extra space.

```c++
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        assert(!nums.empty());

        int sum = 0;
        unordered_map<int, int> m;
        m.insert({0, -1});
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (k != 0) {
                sum %= k;
            }
            if (m.find(sum) != m.end()) {
                if (i - m[sum] > 1) {
                    return true;
                }
            } else {
                m[sum] = i;
            }
        }

        return false;
    }
};
```
