# 452-Minimum Number of Arrows to Burst Balloons

[Problem](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/).

## Approach: Greedy

Idea: Sort the balloons by the end coordinate ascendinly, for the first balloon, the position where we shoot an arrow that can shoot the most balloons at once is its end coordinate. Why? If there is another different position where we shoot an arrow that can shoot more balloons at once, that means there is a balloon later in the list that has an end coordinate to the left of the first balloon, which contradicts with the face that the balloons are sorted ascendingly by the end coordinate. For later balloons, maintain the rightmost arrow we've shoot so far in lastArrow, it the begin coordinate of a balloon is to the left of lastArrow, then we don't need to shoot a new arrow, otherwise we shoot a new arrow at the end coordinate of the balloon and update lastArrow.

Steps:

* Sort the balloons by end coordinate x_end.
* Initialize lastArrow to be the end coordinate of the first balloon.
* Iterate the balloons once:
  * If the balloons starts after lastArrow, we need to shoot a new arrow, increase the number of arrows by one and update lastArrow.

Time complexity: O(nlogn).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty())
            return 0;

        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; }
            );

        int minArrowShots = 1;
        int lastArrow = points[0][1];
        for (const auto& point : points) {
            if (point[0] > lastArrow) {
                minArrowShots++;
                lastArrow = point[1];
            }
        }
        return minArrowShots;
    }
};
```
