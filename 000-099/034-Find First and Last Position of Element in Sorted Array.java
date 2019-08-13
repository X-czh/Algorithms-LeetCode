class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = 0;
        int last = 0;
        int mid = 0;
        int n = nums.length;
        
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (right + 1 < n)
            first = nums[right + 1] == target ? right + 1 : -1;
        else
            first = -1;
        
        left = 0;
        right = n - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (left > 0)
            last = nums[left - 1] == target ? left - 1 : -1;
        else
            last = -1;
        
        return new int[]{first, last};
    }
}
