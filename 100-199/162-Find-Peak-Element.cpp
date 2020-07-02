// Time complexity: O(logn)
// Space complexity: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left {0};
        int right {nums.size() - 1};
        
        while (left < right) {
            int mid {left + (right - left) / 2};
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};

// Alternative implementation
class Solution2 {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if ((mid == 0 || nums[mid - 1] < nums[mid]) &&
                (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]))
                return mid;
            if (nums[mid] > nums[mid + 1]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return 0;
    }
};
