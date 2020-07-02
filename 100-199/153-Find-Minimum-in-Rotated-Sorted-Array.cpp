// Time complexity: O(logn).
// Space complexity: O(1).

class Solution {
public:
    int findMin(vector<int>& nums) {
        // find the pivot of rotation (where nums[p - 1] < nums[p]) and return
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= nums[lo]) {
                if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
                    return nums[mid + 1];
                }
                lo = mid + 1;
            } else {
                if (mid > 0 && nums[mid] < nums[mid - 1]) {
                    return nums[mid];
                }
                hi = mid - 1;
            }
        }

        // if no pivot found, then the array is sorted, return the first element
        return nums.front();
    }
};
