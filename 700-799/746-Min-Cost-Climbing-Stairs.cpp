// Time complexity: O(n).
// Space complexity: O(1).

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = cost.size();
        
        vector<int> min_costs(N + 1, 0);
        for (int i = 2; i < N + 1; ++i) {
            min_costs[i] = min(min_costs[i - 2] + cost[i - 2], min_costs[i - 1] + cost[i - 1]);
        }
        
        return min_costs.back();
    }
};
