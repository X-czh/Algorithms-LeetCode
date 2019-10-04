# 560-Subarray Sum Equals K

[Problem](https://leetcode.com/problems/subarray-sum-equals-k/)

See its tree-variant: Problem [437](../400-499/437-Path%20Sum%20III.md).

## Approach 1: Brute Force

Time complexity: O(n^2).
a
Space complexity: O(1) extra space.

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();
        
        int res = 0;
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = i; j < N; j++) {
                sum += nums[j];
                if (sum == k) res++;
            }
        }
        return res;
    }
};
```

## Approach 2: Hash Map

Key intuition: if the difference between two cumulative sums is k, then there is a subarray of sum k resides between the ending points of the two cumulative sums.

Iterate through the array once, store the occurences of the cumulative sums in a hash map m, for every position i, increment the count by m[cumulative_sum(i) - k].

Time complexity: O(n).

Space complexity: O(n) extra space.

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> m;
        m.insert({0, 1});
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m.find(sum - k) != m.end())
                count += m[sum - k];    
            m[sum]++;
        }
        return count;
    }
};
```
