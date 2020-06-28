// Greedy: sort by priceA - priceB.
// Time complexity: O(nlogn).
// Space complexity: O(1) extra space.

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size();
        assert(N % 2 == 0);
        sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
            return a.front() - a.back() < b.front() - b.back(); 
        });
        
        int cost = 0;
        for (int i = 0; i < N / 2; i++) {
            cost += costs[i].front();
        }
        for (int i = N / 2; i < N; i++) {
            cost += costs[i].back();
        }
        return cost;
    }
};
