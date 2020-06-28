# 011-Container With Most Water

## Approach: Two Pointers

The volume of the container is determined by the shorter bar. Use two pointers to get two bars. After we evaluate the area of a specific container, we should move the shorter bar, because if we change the higher bar, the volume will either decrease or remain the same as we are moving inward. However, if we move the shorter bar, we might get a volume that is larger than the previous one.

Time complexity: O(n).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int max_area = 0;
        while (left < right) {
            int left_height = height[left];
            int right_height = height[right];

            int area = min(left_height, right_height) * (right - left);
            max_area = max(area, max_area);

            if (left_height >= right_height) {
                --right;
            } else {
                ++left;
            }
        }

        return max_area;
    }
};
```
