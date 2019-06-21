// Time complexity: O(n).
// Space complexity: O(1).

class Solution1 {
public:
    int missingNumber(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int sum = (0 + n) * (n + 1) / 2;
        for (auto num : nums) {
            sum -= num;
        }
        return sum;
    }
};

class Solution2 {
public:
    int missingNumber(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int sum = (0 + n) * (n + 1) / 2;
        int vector_sum = accumulate(nums.begin(), nums.end(), 0);
        return sum - vector_sum;
    }
};
