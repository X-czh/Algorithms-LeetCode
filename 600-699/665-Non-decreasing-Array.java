class Solution {
    public boolean checkPossibility(int[] nums) {
        int count = 0;
        int prev_max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                count += 1;
                if (nums[i + 1] >= prev_max) {
                    nums[i] = nums[i + 1];
                } else {
                    nums[i + 1] = nums[i];
                }
            }
            prev_max = nums[i];
        }
        return (count <= 1);
    }
}