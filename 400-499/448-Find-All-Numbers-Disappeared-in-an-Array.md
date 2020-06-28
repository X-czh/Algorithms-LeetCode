# 448-Find All Numbers Disappeared in an Array

[Problem](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

## Approach 1: Recored appeared numbers

Time complexity: O(n).

Space complexity: O(n) extra space.

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> appear(nums.size(), false);
        for (int num : nums) {
            appear[num - 1] = true;
        }
        
        vector<int> disappeared_numbers;
        for (int i = 0; i < nums.size(); i++) {
            if (appear[i] == false) {
                disappeared_numbers.push_back(i + 1);
            }
        }
        
        return disappeared_numbers;
    }
};
```

## Approach 2: Place number at A[number - 1]

First scan through the array, whenever the visited number num is not placed at the num-th position of A, aka, A[i] != i + 1, swap A[i] and A[A[i] - 1] so that num is placed at the right position. If the swapped number num_swapped != i + 1 either, keep swapping until the right number is placed at A[i] or an endless loop occurs (the two swapped numbers are equal). Then scan through the array a second time, find all indices i s.t. A[i] != i + 1, abnd they are the missing numbers.

Time complexity: O(n).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while(nums[i] != i + 1 && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        vector<int> disappeared_numbers;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                disappeared_numbers.push_back(i + 1);
            }
        }
        return disappeared_numbers;
    }
};
```
