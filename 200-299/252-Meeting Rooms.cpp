// Time complexity: O(nlogn).
// Space complexity: O(1) extra space.

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a.front() < b.front(); });
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1].back() > intervals[i].front())
                return false;
        }
        return true;
    }
};
