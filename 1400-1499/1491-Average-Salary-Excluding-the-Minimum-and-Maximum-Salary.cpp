// Time complexity: O(n)
// Space complexity: O(1) extra space

class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0;
        int min_val = numeric_limits<int>::max();
        int max_val = numeric_limits<int>::min();
        for (auto n : salary) {
            sum += n;
            min_val = min(min_val, n);
            max_val = max(max_val, n);
        }
        sum -= min_val;
        sum -= max_val;
        return (double)sum / (salary.size() - 2);
    }
};
