# 042-Trapping Rain Water

[Problem](https://leetcode.com/problems/trapping-rain-water/)

## Approach 1: Brute Force

For each element in the array, we find the maximum level of water it can trap after the rain, which is equal to the minimum of the maximum height of bars on both sides minus its own height.

Time complexity: O(n^2).

Space complexity: O(1).

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int trapped_water = 0;

        for (auto i = 0; i < height.size(); ++i) {
            int max_left = 0, max_right = 0;
            for (auto j = 0; j < i; ++j) {
                max_left = max(max_left, height[j]);
            }
            for (auto j = i + 1; j < height.size(); ++j) {
                max_right = max(max_right, height[j]);
            }
            trapped_water += max(min(max_left, max_right) - height[i], 0);
        }

        return trapped_water;
    }
};
```

## Approach 2: Dynamic Programming

Instead of computing the maximum height of bars to the left and right side of each element in the array repeatedly, we can use dynamic programming to compute that more efficiently.

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int trapped_water = 0;

        int size = height.size();
        vector<int> max_left(size), max_right(size);

        // store max_left for each pos
        max_left[0] = height[0];
        for (auto i = 1; i < size; ++i) {
            max_left[i] = max(height[i], max_left[i - 1]);
        }

        // store max_right for each pos
        max_right[size - 1] = height[size - 1];
        for (auto i = size - 2; i >= 0; --i) {
            max_right[i] = max(height[i], max_right[i + 1]);
        }

        // update trapped_water
        for (auto i = 1; i < size - 1; ++i) {
            trapped_water += max(min(max_left[i], max_right[i]) - height[i], 0);
        }

        return trapped_water;
    }
};
```

## Approach 3: Monotonic Stack

Time complexity: O(n).

Space complexity: O(n).

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int trapped_water = 0;

        stack<int> s;
        for (int i = 0; i < height.size(); i++)
            while (!s.empty() && height[s.top()] < height[i]) {
                int top = s.top();
                s.pop();
                if (s.empty())
                    break;
                int distance = curr - s.top() - 1;
                int bounded_height = min(height[i], height[s.top()]) - height[top];
                trapped_water += distance * bounded_height;
            }
            s.push(i);
        }

        return trapped_water;
    }
};
```

## Approach 4: Two Pointers

Use two pointers, which starts iteration from the left and right side of the array respectively, and maintain left_max and right_max during the iteration. If there is a larger bar at one end (say right), we are assured that the water trapped would be dependant on height of bar in the direction from left to right. As soon as we find the bar at other end (right) is smaller, we start iterating in the opposite direction from right to left.

Time complexity: O(n), single iteration.

Space complexity: O(1) auxiliary space.

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int trapped_water = 0;

        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                left_max = max(left_max, height[left]);
                trapped_water += left_max - height[left];
                left++;
            } else {
                right_max = max(right_max, height[right]);
                trapped_water += right_max - height[right];
                right--;
            }
        }

        return trapped_water;
    }
};
```
