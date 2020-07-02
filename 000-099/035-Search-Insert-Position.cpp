// Time complexity: O(logn).
// Space complexity: O(1)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = -1;

        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                idx = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return idx + 1;
    }
};
