# 041-First Missing Positive

[Problem](https://leetcode.com/problems/first-missing-positive/)

## Approach 1: Hash Set

By the Pigeon Hole Principle, the first missing positive numbers must be between 1 and nums.size() + 1 (inclusive). We just iterate through [1, nums.size() + 1] and return the smallest one not found in our hash set (containing all input numbers).

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }

        for (auto i = 1; i <= nums.size() + 1; ++i) {
            if (s.find(i) == s.end()) {
                return i;
            }
        }
        return -1; // error
    }
};
```

## Approach 2: In-place Bucket Sort

Usual bucket sort takes additional memory. However, we can do it in-place here. We only care about numbers that are between 1 and nums.size() (inclusive), and we put such a number n in nums[n - 1]. The first missing positive number would be i + 1, where i is the first positive number within range such that nums[i] != i + 1 or i = nums.size().

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        inPlaceBucketSort(nums);

        int i = 0;
        for (; i < nums.size() && nums[i] == i + 1; ++i);
        return i + 1;
    }
private:
    void inPlaceBucketSort(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] > 0 && nums[i] <= nums.size() &&
                nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                ++i;
            }
        }
    }
};
```
