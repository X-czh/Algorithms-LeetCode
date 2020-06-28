// Time complexity: O(n^2).
// Space complexity: O(1).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int N = nums.size();
        assert(N >= 3);

        sort(nums.begin(), nums.end());
        int closest_diff = numeric_limits<int>::max();

        for (auto i = 0; i < N - 2; ++i) {
            int left = i + 1;
            int right = N - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = sum - target;

                if (abs(diff) < abs(closest_diff)) {
                    closest_diff = diff;
                }

                if (diff == 0) {
                    return target;
                } else if (diff < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return target + closest_diff;
    }
};
