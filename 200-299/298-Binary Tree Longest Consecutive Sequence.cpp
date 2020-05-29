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

// Iterative solution
// Time complexity: O(n).
// Space complexity: O(n).
class Solution1 {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root)
            return 0;

        int ans = 1;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});

        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            TreeNode* curr = p.first;
            int currSeqlen = p.second;
            ans = max(ans, currSeqlen);

            if (curr->left) {
                int newSeqlen = curr->left->val == curr->val + 1 ? currSeqlen+1 : 1;
                s.push({curr->left, newSeqlen});
            }
            if (curr->right) {
                int newSeqlen = curr->right->val == curr->val + 1 ? currSeqlen+1 : 1;
                s.push({curr->right, newSeqlen});
            }
        }

        return ans;
    }
};

// Recursive solution
// Time complexity: O(n).
// Space complexity: O(n).
class Solution2 {
public:
    int longestConsecutive(TreeNode* root) {
        return dfs(root, nullptr, 0);
    }
private:
    int dfs(TreeNode* node, TreeNode* parent, int len) {
        if (!node) return len;
        len = (parent && node->val == parent->val + 1) ? len + 1 : 1;
        return max(len, max(dfs(node->left, node, len), dfs(node->right, node, len)));
    }
};
