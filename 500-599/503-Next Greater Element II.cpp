// Brute Force 
// Time complexity: O(n^2).
// Space complexity: O(1).
class Solution1 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums.size(); j++) {
                if (nums[(i + j) % nums.size()] > nums[i]) {
                    res[i] = nums[(i + j) % nums.size()];
                    break;
                }
            }
        }
        return res;
    }
};

// Monotonic Stack
// Circular List ? Just go over the list twice!
// Time complexity: O(n).
// Space complexity: O(n).
class Solution2 {
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
