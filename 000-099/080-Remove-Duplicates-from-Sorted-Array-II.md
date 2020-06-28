# 080-Remove Duplicates from Sorted Array II

[Problem](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

## Approach

This problem is a variant of 026, with at most 2 duplicates allowed.

My first intuition is to introduce a flag indicating the number of duplicates seen, in the case of at most 2 duplicates, a bool flag suffices.

A more elegant solution is to compare the i-th number and the (i - 2)-th number, as long as they are not the same, there are no more than 2 duplicates.

Time complexity: O(n).

Space complexity: O(1) extra memory.

```c++
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;
        bool buffer_flag = true;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
                buffer_flag = true;
            } else if (buffer_flag) {
                i++;
                nums[i] = nums[j];
                buffer_flag = false;
            }
        }
        return i + 1;
    }
};


// More elegant
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto num : nums) {
            if (i < 2 || nums[i - 2] != num) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
```

The algorithm can further be generealized for allowing at most k duplicates:

```c++
class Solution {
public:
    int removeDuplicates(int k, vector<int>& nums) {
        int i = 0;
        for (auto num : nums) {
            if (i < k || nums[i - k] != num) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
```
