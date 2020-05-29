# K-Sum

Does a given set of N integers contains K elements that sum to a target number?

## 2-Sum

### Appraoch 1: Brute Force

Time complexity: O(n^2).

Space complexity: O(1).

```c++
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
```

### Appraoch 2: Sorting + Two Pointers

First sort the array, then maintain two pointers, starting from the smallest and the largest number, iteratively approaching our target.

Time complexity: O(nlogn).

Space complexity: O(1).

```c++
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
```

### Appraoch 3: Hash Map

Time complexity: O(n).

Space complexity: O(n).

```c++
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
```

## 2-Sum Closest

## K-Sum AND K-Sum Closest (K > 2)

K-Sum problem can be converted to (K - 1)-Sum problem by fixing one number and solving the (K - 1)-Sum problem on the rest of the array.
