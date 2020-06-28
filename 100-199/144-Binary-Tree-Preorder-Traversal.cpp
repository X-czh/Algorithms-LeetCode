// Time complexity: O(n)
// Space complexity: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive Solution 1
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        vector<int> preorder;
        
        preorder.push_back(root->val);
        
        auto preorder_left = preorderTraversal(root->left);
        preorder.insert(preorder.end(), preorder_left.begin(), preorder_left.end());
        auto preorder_right = preorderTraversal(root->right);
        preorder.insert(preorder.end(), preorder_right.begin(), preorder_right.end());
        
        return preorder;
    }
};

// Recursive Solution 2
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
private:
    void helper(TreeNode* root, vector<int>& result) {
        if (root) {
            result.push_back(root->val);
            helper(root->left, result);
            helper(root->right, result);
        }
    }
};

// Iterative Solution
class Solution3 {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> preorder;
        stack<TreeNode*> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode* curr = s.top();
            s.pop();
            preorder.push_back(curr->val);

            if (curr->right) {
                s.push(curr->right);
            }
            if (curr->left) {
                s.push(curr->left);
            }
        }
        
        return preorder;
    }
};