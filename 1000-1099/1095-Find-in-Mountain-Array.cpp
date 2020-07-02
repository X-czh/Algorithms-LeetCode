// Time complexity: O(logn).
// Space complexity: O(1).

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        
        // find peak
        int peak = -1;
        int lo = 1;
        int hi = len - 2;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int prev_mid_val = mountainArr.get(mid - 1);
            int mid_val = mountainArr.get(mid);
            int succ_mid_val = mountainArr.get(mid + 1);
            if (prev_mid_val < mid_val && mid_val > succ_mid_val) {
                peak = mid;
                break;
            }
            if (prev_mid_val < mid_val) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        // binary search on increasing part
        lo = 0;
        hi = peak - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int mid_val = mountainArr.get(mid);
            if (mid_val == target) {
                return mid;
            } else if (mid_val < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        // binary search on decreasing part
        lo = peak;
        hi = len - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int mid_val = mountainArr.get(mid);
            if (mid_val == target) {
                return mid;
            } else if (mid_val < target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return -1;
    }
};
