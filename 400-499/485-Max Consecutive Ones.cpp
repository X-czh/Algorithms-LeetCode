// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int max_cnt = 0;
        for (auto n : nums) {
            if (n == 1) {
                cnt++;
            } else {
                max_cnt = max(max_cnt, cnt);
                cnt = 0;
            }
        }
        max_cnt = max(max_cnt, cnt);
        return max_cnt;
    }
};
