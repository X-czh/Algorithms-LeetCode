class Solution {
    public int searchInsert(int[] nums, int target) {
        int mid = 0;
        int left = 0;
        int right = nums.length - 1;
        
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        
        if (nums[mid] > target)
            return mid;
        else
            return mid + 1;
    }
}