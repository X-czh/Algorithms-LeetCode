# 084-Largest Rectangle in Histogram

[Problem](https://leetcode.com/problems/largest-rectangle-in-histogram/)

## Approach 1: Brute Force (Time Limit Exceeded)

Time complexity: O(n^2).

Space complexity: O(1).

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {
            int min_height = heights[i];
            for (int j = i; j < heights.size(); j++) {
                min_height = min(min_height, heights[j]);
                max_area = max(max_area, min_height * (j - i + 1));
            }
        }

        return max_area;
    }
};
```

## Approach 2: Divide and Conquer

Observation: the rectangle with maximum area will be the maximum of:

* The widest possible rectangle with height equal to the height of the shortest bar.
* The largest rectangle confined to the left of the shortest bar(subproblem).
* The largest rectangle confined to the right of the shortest bar(subproblem).

Time complexity: Use Master Theorem. In average, T(n) = 2T(n/2) + O(n) so T(n) = O(nlogn) in average. In worst case where the numbers in the array are sorted, T(n) = T(n-1) + O(n) so T(n) = O(n^2), and we don't gain the advantage of divide and conquer.

Space complexity: O(n).

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return largestRectangleAreaHelper(heights, 0, heights.size());
    }

    int largestRectangleAreaHelper(vector<int>& heights, int left, int right) {
        if (left >= right) return 0;

        int min_height = heights[left];
        int min_height_idx = left;
        for (int i = left; i < right; i++) {
            if (heights[i] < min_height) {
                min_height = heights[i];
                min_height_idx = i;
            }
        }

        return max({
            largestRectangleAreaHelper(heights, left, min_height_idx),
            (right - left) * min_height,
            largestRectangleAreaHelper(heights, min_height_idx + 1, right)
        });
    }
};
```

## Approach 3: Better Divide and Conquer with Segment Tree

We gain the advantage of divide and conquer by dividing the large problem into substantially smaller subproblems. But, we won't gain much advantage if the array happens to be sorted in either ascending or descending order, since every time we need to find the minimum number in a large subarray in O(n), and the overall complexity becomes O(n^2) in the worst case. We can reduce the time complexity by using a Segment Tree to find the minimum every time in O(logn) time.

Time complexity: O(nlogn).

Space complexity: O(n).

Implementation is omitted. (Segment Tree is rather complicated to implement...)

## Approach 4: Monotonic Stack

In this approach, we maintain a monotonic stack that stores the indexes of the bars. The height of the indexed bars is kept monotonically increasing from top to bottom in stack. Initially, we push a -1 onto the stack to mark the end. We start with the leftmost bar and keep pushing the current bar's index onto the stack until the bar's height is decreasing, i.e. heights[i] < heights[i-1]. Now, we start popping the numbers from the stack until we hit a number stack[j] on the stack such that stack[j] <= heights[i].

Every time we pop, we find out the area of rectangle formed using the current element as the height of the rectangle and the difference between the the current element's index pointed to in the original array and the element stack[top - 1] - 1 as the width i.e. if we pop an element stack[top] and i is the current index to which we are pointing in the original array, the current area of the rectangle will be considered as: (i - stack[top - 1] - 1) * heights[stack[top]].

Further, if we reach the end of the array, we pop all the elements of the stack and at every pop, this time we use the following equation to find the area: (heights.length - stack[top - 1] - 1) * heights[stack[top]]. Thus, we can get the area of the of the largest rectangle by comparing the new area found everytime.

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_area = 0;
        const int n = heights.size();

        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && heights[s.top()] > heights[i]) {
                int height = heights[s.top()];
                s.pop();
                max_area = max(max_area, height * (i - s.top() - 1));
            }
            s.push(i);
        }
        while (s.top() != -1) {
            int height = heights[s.top()];
            s.pop();
            max_area = max(max_area, height * (n - s.top() - 1));
        }

        return max_area;
    }
};
```
