# 033-Search in Rotated Sorted Array

[Problem](https://leetcode.com/problems/search-in-rotated-sorted-array/)

## Naive Approach

Do the linear scan and find the element in O(n) time with O(1) extra space.

## Better Approach

We can still apply the binary search with extra logic. Nomarlly, when target < array[mid], we search the left half of the array. Now that the array is rotated, there are more possiblities to take care of. If array[mid] > array[left], i.e., the mid is on the LARGE side, we search the left half of the array. If array [mid] < array[left], i.e., the mid is on the SMALL side, the target may on the left or right half of the array. In this case, if target <= nums[right], target is on the right half of the array, otherwise target is on the left half of the array. If array[mid] = array[left], mid = left, and we search the right half of the array. When target > array[mid], similar logic applies.

Time complexity: O(logn).

Space complexity: O(1).

```c++
class Solution1 {
    using size_type = vector<int>::size_type;
public:
    int search(vector<int>& nums, int target) {
        size_type left{0};
        size_type right{nums.size() - 1};

        while (left <= right) {
            size_type mid{left + (right - left) / 2};
            if (target > nums[mid]) {
                if (nums[mid] > nums[left]) { // mid on the LARGE side
                    left = mid + 1;
                } else if (nums[mid] < nums[left]) { // mid on the SMALL side
                    if (target <= nums[right]) { // target on the SMALL side
                        left = mid + 1;
                    } else { // target on the BIG side
                        right = mid - 1;
                    }
                } else { // left = mid
                    left = mid + 1;
                }
            } else if (target < nums[mid]) {
                if (nums[mid] > nums[left]) { // mid on the LARGE side
                    if (target >= nums[left]) { // target on the LARGE side
                        right = mid - 1;
                    } else { // target on the SMALL side
                        left = mid + 1;
                    }
                } else if (nums[mid] < nums[left]) { // mid on the SMALL side
                    right = mid - 1;
                } else { // left = mid
                    left = mid + 1;
                }
            } else {
                return mid;
            }
        }

        return -1;
    }
};


// A more concise version
class Solution2 {
    using size_type = vector<int>::size_type;
public:
    int search(vector<int>& nums, int target) {
        size_type left{0};
        size_type right{nums.size() - 1};

        while (left <= right) {
            size_type mid{left + (right - left) / 2};
            if (target == nums[mid]) {
                return mid;
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

        return -1;
    }
};
```
