# 033-Search in Rotated Sorted Array

[Problem](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## Approach 1: Linear Scan

Do the linear scan and find the element in O(n) time with O(1) extra space.

## Approach 2: Binary Search

Observation: If a sorted array is shifted, if you take the middle, always one side will be sorted.

We can thus apply binary search. At each iteration, check whether nums[mid] == target, if so, we are done. Otherwise, check which side is sorted, and check whether target falls into that side, and reduce the search scope by half accordingly.

Time complexity: O(logn).

Space complexity: O(1).

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] >= nums[lo]) { // left half is sorted
                if (target >= nums[lo] && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            } else { // right half is sorted
                if (target > nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
        }
        return -1;
    }
};
```
