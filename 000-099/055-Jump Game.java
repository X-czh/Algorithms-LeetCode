/**
 * Key observation:
 *      We won't get stuck if we do not encounter any zero along the way.
 * Idea:
 *      Based on the key observation, we just need to check whether we can jump
 *      over the zeroes along the way.
 * Solution:
 *      Iterate through the array, maintain a variable that records the farthest
 *      position we can get to so far. Whenever we encounter a zero, check if 
 *      the farthest reacheable position so far is beyond this zero. If yes, 
 *      continue iterating; if no, we jump out of the loop. Finally, check 
 *      whether the last position is within our reachable range.
 */
class Solution {
    public boolean canJump(int[] nums) {
        int max_reachable = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0 && max_reachable == i)
                break;
            max_reachable = Math.max(i + nums[i], max_reachable);
        }
        return (max_reachable >= nums.length - 1);
    }
}