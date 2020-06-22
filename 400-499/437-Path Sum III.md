# 437-Path Sum III

[Problem](https://leetcode.com/problems/path-sum-iii/)

This a tree-variant of Problem [560](../500-599/560-Subarray%20Sum%20Equals%20K.md).

## Approach 1: Brute Force (DFS + BFS)

BFS to iterate tree, from each node, run DFS to count number of path sums that equals target.

Time complexity: O(n^2).

Space complexity: O(n) extra space.

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;

        int count = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            count += dfs_count(curr, sum);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        return count;
    }
private:
    int dfs_count(TreeNode* root, int sum) {
        int count = 0;
        if (root->val == sum) count++;
        if (root->left) count += dfs_count(root->left, sum - root->val);
        if (root->right) count += dfs_count(root->right, sum - root->val);
        return count;
    }
};
```

## Approach 1': DFS + DFS

DFS to iterathe tree, but we include a state variable to indicate whether path is started during the recursion. If path has been started, run DFS to count number of path sums that equals target. If not, either continuing skipping the children nodes, or start the path from the children nodes.

This formulation is equivalant to: DFS to iterate tree, from each node, run DFS to count number of path sums that equals target.

Time complexity: O(n^2).

Space complexity: O(n) extra space.

```c++
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        return helper(root, sum, true) + helper(root, sum, false);
    }
private:
    int helper(TreeNode* node, int sum, bool path_start) {
        if (!node) return 0;

        int left = 0, right = 0, count = 0;
        if (path_start) {
            left = helper(node->left, sum - node->val, true);
            right = helper(node->right, sum - node->val, true);
            count = (sum == node->val ? 1 : 0) + left + right;
        } else {
            left = helper(node->left, sum, false) + helper(node->left, sum, true);
            right = helper(node->right, sum, false) + helper(node->right, sum, true);
            count = left + right;
        }
        return count;
    }
};
```

## Approach 2: Hash Map (Prefix Sum)

Key intuition: if the difference between two prefix sums = target, then there exist a tree segment between the ending points of the two prefix sums with sum = target.

DFS the tree once, store the occurrences of prefix sums in a hash map, for every node i, increment the count by m[prefix_sum(i) - target]. Note that to maintain the prefix sum, every time DFS exits from visiting a node, we should decrement the occurrence of the prefix sum to mark exiting from visiting this node.

Time complexity: O(n).

Space complexity: O(n) extra space.

```c++
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m; // stores occurrences of prefix sum
        m.insert({0, 1});
        return pathSumHelper(root, 0, sum, m);
    }
private:
    int pathSumHelper(TreeNode* root, int curr, int sum, unordered_map<int, int>& m) {
        if (!root) return 0;

        curr += root->val;
        int count = m[curr - sum];

        m[curr]++;
        count += pathSumHelper(root->left, curr, sum, m);
        count += pathSumHelper(root->right, curr, sum, m);
        m[curr]--;

        return count;
    }
};
```
