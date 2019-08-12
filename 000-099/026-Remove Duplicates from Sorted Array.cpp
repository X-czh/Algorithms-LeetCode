// Time complexity: O(n).
// Space complexity: O(1) extra memory.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (auto num : nums) {
            if (i < 1 || nums[i - 1] != num) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
