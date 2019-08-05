// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto i = 0; i < nums.size(); ++i) {
            auto found = m.find(nums[i]);
            if (found != m.end()) {
                if (abs(found->second - i) <= k) return true;
                found->second = i;
            } else {
                m.insert({nums[i], i});
            }
        }
        return false;
    }
};
