# 501-Find Mode in Binary Search Tree

[Problem](https://leetcode.com/problems/find-mode-in-binary-search-tree/)

## Approach 1: Hash Map for Counting

Time complexity: O(n).

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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counts;
        int max_count = 0;
        DFS(root, counts, max_count);

        vector<int> modes;
        for (const auto& p : counts) {
            if (p.second == max_count) {
                modes.push_back(p.first);
            }
        }
        return modes;
    }
private:
    void DFS(TreeNode* root, unordered_map<int, int>& counts, int& max_count) {
        if (root) {
            ++counts[root->val];
            max_count = max(max_count, counts[root->val]);
            DFS(root->left, counts, max_count);
            DFS(root->right, counts, max_count);
        }
    }
};
```

## Approach 2: Inorder Traversal

You traverse the BST in a sorted manner if you do an inorder traversal.

Time complexity: O(n).

Space complexity: O(1) extra space.

```c++
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if (!root) return {};

        int pre_val = root->val;
        int count = 0;
        int max_count = 0;
        vector<int> modes;

        inorder(root, pre_val, count, max_count, modes);

        if (count == max_count) {
            modes.push_back(pre_val);
        } else if (count > max_count) {
            max_count = count;
            modes.clear();
            modes.push_back(pre_val);
        }
        cout << max_count;

        return modes;
    }
private:
    void inorder(TreeNode* root, int& pre_val, int& count, int& max_count, vector<int>& modes) {
        if (root->left) inorder(root->left, pre_val, count, max_count, modes);

        if (root->val == pre_val) {
            ++count;
        } else {
            if (count == max_count) {
                modes.push_back(pre_val);
            } else if (count > max_count) {
                max_count = count;
                modes.clear();
                modes.push_back(pre_val);
            }
            pre_val = root->val;
            count = 1;
        }

        if (root->right) inorder(root->right, pre_val, count, max_count, modes);
    }
};
```
