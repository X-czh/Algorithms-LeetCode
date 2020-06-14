# 056-Merge Intervals

[Problem](https://leetcode.com/problems/merge-intervals/)

## Approach 1: Sorting

Intution: If we sort the intervals by their start value, then each set of intervals that can be merged will appear as a contiguous "run" in the sorted list.

Time complexity: O(nlogn).

Space complexity: O(1) (in-place) or O(n) (modification prohibited).

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y)
             { return x.front() < y.front(); });

        vector<vector<int>> merged{intervals.front()};
        for (const auto& interval : intervals) {
            if (merged.back().back() < interval.front()) {
                merged.push_back(interval);
            } else {
                merged.back().back() = max(merged.back().back(), interval.back());
            }
        }

        return merged;
    }
};
```
