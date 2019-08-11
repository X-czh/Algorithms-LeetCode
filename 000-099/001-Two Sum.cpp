// Approach 1: Brute Force
// Time complexity: O(n^2).
// Space complexity: O(1).

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (auto i = 0; i < nums.size(); ++i) {
            for (auto j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Approach 2: Hash Map
// Time complexity: O(n).
// Space complexity: O(n).

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> look_up;

        for (auto i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto found = look_up.find(complement);
            if (found != look_up.end()) {
                return {found->second, i};
            }
            look_up.insert({nums[i], i});
        }

        return {};
    }
};
