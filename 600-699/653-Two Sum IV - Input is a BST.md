# Two Sum IV - Input is a BST

[Problem](https://leetcode.com/problems/two-sum-iv-input-is-a-bst/)

## Approach 1: Tree Traversal + HashSet

Time complexity: O(N).

Space complexity: O(N).

### First Attempt: traverse the tree values twice at worst

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        dfs(root, s);
        for (int n : s) {
            int complement = k - n;
            if (n != complement && s.find(complement) != s.end())
                return true;
        }
        return false;
    }
private:
    void dfs(TreeNode* root, unordered_set<int>& s) {
        if (!root) return;

        s.insert(root->val);
        dfs(root->left, s);
        dfs(root->right, s);
    }
};
```

### Better: traverse the tree values once at worst

```c++
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return find(root, k, s);
    }
private:
    bool find(TreeNode* root, int k, unordered_set<int>& s) {
        if (!root) return false;

        int complement = k - root->val;
        if (s.find(complement) != s.end())
            return true;

        s.insert(root->val);
        return find(root->left, k, s) || find(root->right, k, s);
    }
};
```

## Approach 2: Inorder traverse the BST to get a sorted list, reducing to Two Sum (Sorted)

Time complexity: O(N).

Space complexity: O(N).

```c++
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);

        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == k)
                return true;
            else if (sum > k)
                right--;
            else
                left++;
        }
        return false;
    }
private:
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
};
