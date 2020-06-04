// Monotonic Stack
// Circular List ? Just go over the list twice!
// Time complexity: O(n).
// Space complexity: O(n).

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> s;
        for (int j = 0; j < 2; j++) {
            for (int i = nums.size() - 1; i >= 0; i--) {
                while (!s.empty() && nums[i] >= s.top()) {
                    s.pop();
                }
                ans[i] = s.empty() ? -1 : s.top();
                s.push(nums[i]);
            }
        }
        return ans;
    }
};
