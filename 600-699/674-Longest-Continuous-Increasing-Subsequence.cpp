// Time complexity: O(n^2).
// Space complexity: O(n).

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        int len = 1;
        int max_len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                len++;
                max_len = max(len, max_len);
            } else {
                len = 1;
            }
        }
        return max_len;
    }
};
