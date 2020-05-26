// Time complexity: O(sqrt(target)).
// Space complexity: O(1).

// Math trick: https://leetcode.com/problems/reach-a-number/solution/.

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        
        int k = 0;
        while (target > 0) {
            k++;
            target -= k;
        }
        
        return target % 2 == 0 ? k : k + 1 + k % 2; 
    }
};
