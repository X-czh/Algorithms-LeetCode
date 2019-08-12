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

// Appraoch 2: Sorting + Two Pointers
// Time complexity: O(nlogn).
// Space complexity: O(1).

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                return {left, right};
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }

        return {};
    }
};

// Approach 3: Hash Map
// Time complexity: O(n).
// Space complexity: O(n).

class Solution3 {
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
