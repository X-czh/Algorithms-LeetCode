// Convert to 2Sum case
// Notice the handling of duplicated elements

// Time complexity: O(n^2).
// Space complexity: O(1).

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int N = nums.size();
        if (N < 3) return {};

        vector<vector<int>> ans;        
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < N - 2) {
            int num_1 = nums[i];

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int num_2 = nums[left];
                int num_3 = nums[right];
                int sum = num_1 + num_2 + num_3;
                if (sum == 0) {
                    ans.push_back({num_1, num_2, num_3});
                    while (left < right && nums[left] == num_2) ++left;
                    while (left < right && nums[right] == num_3) --right;
                } else if (sum < 0) {
                    while (left < right && nums[left] == num_2) ++left;
                } else {
                    while (left < right && nums[right] == num_3) --right;
                }
            }

            while (i < N - 2 && nums[i] == num_1) ++i;
        }

        return ans;
    }
};
