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

// Recursive
// Time complexity: O(N), N is the number of nodes in the tree.
// Space complexity: O(N) auxilary space.
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
private:
    void helper(TreeNode* root, vector<int>& result) {
        if (root) {
            helper(root->left, result);
            result.push_back(root->val);
            helper(root->right, result);
        }
    } 
};

// Iterative
// Time complexity: O(N), N is the number of nodes in the tree.
// Space complexity: O(N) auxilary space.
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (curr || !s.empty()) {
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
        return result;
    }
};
