// Time complexity: O(logn).
// Space complexity: O(1).

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

// Exponential Search
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if (reader.get(0) == 2147483647) return -1;

        // find an upper bound of index of the smallest element that is larger than target
        int size = 1;
        while (reader.get(size) < target) {
            if (size >= numeric_limits<int>::max() / 2) {
                size = numeric_limits<int>::max();
            } else {
                size *= 2;
            }
        }
        
        // binary search
        int lo = 0;
        int hi = size;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int mid_val = reader.get(mid);
            if (mid_val == target) {
                return mid;
            } else if (mid_val < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};

// An optimization to reduce the initial search space of binary search
class Solution2 {
public:
    int search(const ArrayReader& reader, int target) {
        if (reader.get(0) == 2147483647) return -1;

        // find an upper bound of index of the smallest element that is larger than target
        int lo = 0;
        int hi = 1;
        while (reader.get(hi) < target) {
            if (hi >= numeric_limits<int>::max() / 2) {
                lo = hi;
                hi = numeric_limits<int>::max();
            } else {
                lo = hi;
                hi *= 2;
            }
        }
        
        // binary search
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int mid_val = reader.get(mid);
            if (mid_val == target) {
                return mid;
            } else if (mid_val < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return -1;
    }
};