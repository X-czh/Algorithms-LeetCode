// Time complexity: O(nlogm), where n = nums.length, m = max(nums[i]).
// Space complexity: O(1) extra space.

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (auto num : nums) {
            if (numDigits(num) % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
private:
    int numDigits(int num) {
        if (num == 0)
            return 1;

        int n = 0;
        while (num > 0) {
            num /= 10;
            n++;
        }
        return n;
    }
};
