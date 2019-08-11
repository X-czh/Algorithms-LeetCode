// Convert to 3Sum, then to 2Sum case
// Notice the handling of duplicated elements

// Time complexity: O(n^3).
// Space complexity: O(1).

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int N = nums.size();
        if (N < 4) return {};

        vector<vector<int>> ans;        
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < N - 3) {
            int num_1 = nums[i];

            int j = i + 1;
            while (j < N - 2) {
                int num_2 = nums[j];

                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    int num_3 = nums[left];
                    int num_4 = nums[right];
                    int sum = num_1 + num_2 + num_3 + num_4;
                    if (sum == target) {
                        ans.push_back({num_1, num_2, num_3, num_4});
                        while (left < right && nums[left] == num_3) ++left;
                        while (left < right && nums[right] == num_4) --right;
                    } else if (sum < target) {
                        while (left < right && nums[left] == num_3) ++left;
                    } else {
                        while (left < right && nums[right] == num_4) --right;
                    }
                }

                while (j < N - 2 && nums[j] == num_2) ++j;
            }

            while (i < N - 2 && nums[i] == num_1) ++i;
        }

        return ans;
    }
};
