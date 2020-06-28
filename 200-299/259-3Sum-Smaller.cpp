// Time complexity: O(n^2).
// Space complexity: O(1) extra space.

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());
        int ans = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum >= target) {
                    right--;
                } else {
                    ans += right - left; // Notice: KEY POINT!
                    left++;
                }
            }
        }

        return ans;
    }
};
