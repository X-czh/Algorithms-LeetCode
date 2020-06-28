// Time complexity: O(n).
// Space complexity: O(1).

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty())
            return 0;
        for (int i = 1; i < costs.size(); i++) {
            vector<int>& prev_cost = costs[i-1];
            costs[i][0] += min(prev_cost[1], prev_cost[2]);
            costs[i][1] += min(prev_cost[0], prev_cost[2]);
            costs[i][2] += min(prev_cost[0], prev_cost[1]);
        }
        return *min_element(costs.back().begin(), costs.back().end());
    }
};
