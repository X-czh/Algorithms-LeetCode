# 215-Kth Largest Element in an Array

[Problem](https://leetcode.com/problems/kth-largest-element-in-an-array/)

## Approach 1: Heap

Use C++ STL's priority queue (effectively a heap).

Time complexity: O(n + n) = O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(std::less<int>(), nums);
        for (int i = 0; i < k - 1; ++i) q.pop();
        return q.top();
    }
};
```
