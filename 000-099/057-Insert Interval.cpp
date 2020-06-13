// Greedy
// Time complexity: O(n).
// Space complexity: O(n) to keep the output.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int lo = newInterval[0];
        int hi = newInterval[1];
        
        // special case 1: empty interevals
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }

        // spacial case 2: newIntervals ahead of all intervals
        if (hi < intervals.front()[0]) {
            res.push_back(newInterval);
            for (const auto& interval : intervals) {
                res.push_back(interval);
            }
            return res;
        }
        
        // special case 3: newIntervals fall behind all intervals
        if (lo > intervals.back()[1]) {
            for (const auto& interval : intervals) {
                res.push_back(interval);
            }
            res.push_back(newInterval);
            return res;
        }
        
        // other cases: merging needed
        int merged_lo;
        int merged_hi;
        int i = 0;

        // find the first interval that overlaps with newInterval
        while (i < intervals.size() && intervals[i][1] < lo) {
            res.push_back(intervals[i]);
            i++;
        }
        merged_lo = min(lo, intervals[i][0]);

        // find the last interval that overlaps with newInterval
        while (i < intervals.size() && intervals[i][0] <= hi) {
            i++;
        }
        merged_hi = max(hi, intervals[i - 1][1]);
        
        res.push_back({merged_lo, merged_hi});
        while (i < intervals.size()) {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};
