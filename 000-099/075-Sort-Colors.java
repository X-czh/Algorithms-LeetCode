class Solution {
    public void sortColors(int[] nums) {
        int i = 0, r = 0, b = nums.length - 1;
        int aux;
        while (i <= b) {
            switch (nums[i]) {
                case 0:
                    aux = nums[r];
                    nums[r] = nums[i];
                    nums[i] = aux;
                    r++;
                    i++;
                    break;
                case 1:
                    i++;
                    break;
                case 2:
                    aux = nums[b];
                    nums[b] = nums[i];
                    nums[i] = aux;
                    b--;
                    break;
            }
        }
    }
}