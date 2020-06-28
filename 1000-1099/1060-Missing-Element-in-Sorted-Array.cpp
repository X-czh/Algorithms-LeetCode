// Approach 1: One Pass
// Time complexity: O(n).
// Space complexity: O(1) extra space.
class Solution1 {
public:
    int missingElement(vector<int>& nums, int k) {
        int cnt = 0;
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int diff = nums[i] - curr;
            if (diff > 1) {
                int old_cnt = cnt;
                cnt += diff - 1;
                if (cnt >= k) {
                    return curr + k - old_cnt;
                }
            }
            curr = nums[i];
        }
        return curr + k - cnt;
    }
};

// Approach 2: Binary Search
// Time complexity: O(logn).
// Space complexity: O(1) extra space.
class Solution2 {
public:
    int missingElement(vector<int>& nums, int k) {
        auto num_missing = [&nums](int i) { return nums[i] - nums[0] - i; };

        int left = 0;
        int right = nums.size() - 1;
        // precondition: left = 0 AND right = nums.size() - 1
        // postcondition: left = right AND (left = nums.size() - 1 OR num_missing[left] >= k)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (num_missing(mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // syntax requires C++17 and above
        if (int missing = num_missing(left); missing >= k) {
            return nums[left] - (missing - k + 1);
        } else {
            return nums[left] + (k - missing);
        }
    }
};
