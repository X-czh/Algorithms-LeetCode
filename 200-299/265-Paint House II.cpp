// Time complexity: O(nk).
// Space complexity: O(1).

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        const int n = costs.size();
        if (n == 0)
            return 0;

        const int k = costs[0].size();
        if (k == 0)
            return 0;
        if (k == 1) {
            if (n == 1)
                return costs[0][0];
            return 0;
        }

        // precondition: n >= 1 && k >= 2
        for (int i = 1; i < n; i++) {
            vector<int>& prev_cost = costs[i-1];

            // find min and second_min of prev_cost
            int min = numeric_limits<int>::max();
            int second_min = min;
            for (auto n : prev_cost)  {  
                if (n < min) {  
                    second_min = min;  
                    min = n;
                } else if (n < second_min) {
                    second_min = n;
                }
            }

            for (int j = 0; j < k; j++) {
                costs[i][j] += (prev_cost[j] == min ? second_min : min);
            }
        }

        return *min_element(costs.back().begin(), costs.back().end());
    }
};
