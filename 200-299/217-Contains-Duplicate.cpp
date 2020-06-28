// Approach 1: Naive Linear Search
// Time complexity: O(n^2)
// Space complexity: O(1)

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        for (auto i = 0; i < nums.size(); ++i) {
            for (auto j = 0; j < i; ++j) {
                if (nums[i] == nums[j]) return true;
            }
        }
        return false;
    }
};

// Approach 2: Sorting
// Time complexity: O(nlogn)
// Space complexity: O(1) or O(n)

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;

        sort(nums.begin(), nums.end());
        for (auto i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};

// Approach 3: Hash Set
// Time complexity: O(n)
// Space complexity: O(n)

class Solution3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums) {
            if (s.find(num) != s.end()) return true;
            s.insert(num);
        }
        return false;
    }
};
