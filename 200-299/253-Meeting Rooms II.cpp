// Simulate real-life situation: 
//      when new meeting comes, check if there is already meeting finished to have its room reused
//      if not, add more room.
// Time complexity: O(nlogn).
// Space complexity: O(n) extra space.

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a.front() < b.front();
        });
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> q_end_times;
        q_end_times.push(intervals[0].back());
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].front() >= q_end_times.top())
                q_end_times.pop(); // the room is ready to be reused
            q_end_times.push(intervals[i].back()); // update end time
        }
        return q_end_times.size();
    }
};
