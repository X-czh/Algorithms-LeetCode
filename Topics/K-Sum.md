# K-Sum

Does a given set of N integers contains K elements that sum to a target number?

## 2-Sum

[001-Two Sum](../000-099/001-Two%20Sum.cpp)

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

## 2-Sum Variants

### 2-Sum Closest

```c++
int twoSumClosest(vector<int>& nums, int target) {
    assert(nums.size() >= 2);

    sort(nums.begin(), nums.end());
    int closest_diff = numeric_limits<int>::max();

    int left = 0;
    int right = A.size() - 1;
    while (left < right) {
        int sum = A[left] + A[right];
        int diff = sum - target;

        if (abs(diff) < abs(closest_diff)) {
            closest_diff = diff;
        }

        if (diff == 0) {
            return target;
        } else if (diff < 0) {
            ++left;
        } else {
            --right;
        }
    }

    return target + closest_diff;
}
```

### 2-Sum in BSTs

* [653-Two Sum IV - Input is a BST](../600-699/653-Two%20Sum%20IV%20-%20Input%20is%20a%20BST.md)
* [1214-Two Sum BSTs](../1200-1299/1214-Two%20Sum%20BSTs.cpp)

## K-Sum (K > 2)

K-Sum problem can be converted to (K - 1)-Sum problem by fixing one number and solving the (K - 1)-Sum problem on the rest of the array, and we already know how to solve 2-Sum problem!

Time complexity: O(n^(K-1)).

Space complexity: O(K).

```c++
vector<int> twoSum(vector<int>& nums, int idx, int target) {
    int left = idx;
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

vector<int> KSumHelper(vector<int>& nums, int idx, int target, int K) {
    if (K == 2) return twoSum(nums, idx, target);

    int i = idx;
    while (i < nums.size() - K + 1) {
        vector<int> ans = KSumHelper(nums, i + 1, target - nums[i], K - 1);
        if (!ans.empty()) {
            ans.push_back(i);
            return ans;
        }
    }

    return {};
}

// Precondition: K > 2 && nums.size() >= K
vector<int> KSum(vector<int>& nums, int target, int K) {
    sort(nums.begin(), nums.end());
    return KSumHelper(nums, 0, target, K - 1);
};
```

### Related Problems

* [015-3Sum](../000-099/015-3Sum.cpp)
* [016-3Sum Closest](../000-099/016-3Sum%20Closest.cpp)
* [018-4Sum](../000-099/018-4Sum.cpp)
* [259-3Sum Smaller](../200-299/259-3Sum%20Smaller.cpp)
* [923-3Sum With Multiplicity](../900-999/923-3Sum%20With%20Multiplicity.md)
