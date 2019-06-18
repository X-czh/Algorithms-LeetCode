# 081-Search in Rotated Sorted Array II

[Problem](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

## Algorithm

This is a variant of 033-Search in Rotated Sorted Array with duplicates allowed. In 033, we rely on the comparison between array[mid] and array[left] to figure out the whether the mid is on the LARGE side or the SMALL side. If array[mid] > array[left], the mid is on the LARGE side. If array[mid] < array[left], the mid is on the SMALL side. If array[mid] = array[left], left = mid, and we always search the right half. Now with duplicates, when array[mid] = array[left], there are three possibilities, mid = left, the mid is on the LARGE side (consider [1, 1, 1, 3, 1]), or the mid is on the SMALL side (consider [1, 3, 1, 1, 1]). To solve this issue, we can just step over the duplicated elements on the left to avoid the case where nums[mid] == nums[left]. The time complexity now becomes O(n) due to stepping over the duplicated elements. The worst case is where all the elements in the array are the same, in which the algorithm degrades to the linear scan.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
    using size_type = vector<int>::size_type;
public:
    bool search(vector<int>& nums, int target) {
        size_type left{0};
        size_type right{nums.size() - 1};

        while (left <= right) {
            size_type mid {left + (right - left) / 2};
            if (target == nums[mid]) {
                return true;
            } else if (nums[mid] == nums[left]) {
                // step over duplicated elements on the left
                left++;
            } else if (
                    // mid in the LARGE half
                (nums[mid] > nums[left] && target >= nums[left] && target < nums[mid]) ||
                    // mid in the SMALL half
                (nums[mid] < nums[left] && (target < nums[mid] || target > nums[right]))) {
                // target on the left half
                right = mid - 1;
            } else {
                // target on the right half
                left = mid + 1;
            }
        }

        return false;
    }
};
```
