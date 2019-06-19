class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums == null)
            throw new NullPointerException("Array is null!");
        
        int count = 0;    
        for (int i = 0; i < nums.length; i++) {
            if(nums[i] != val) {
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
}