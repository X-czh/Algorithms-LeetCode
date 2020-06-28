// Inorder Traversal of BST
// Time complexity: O(n).
// Space complexity: O(n).

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> s;
        inorder(root1, target, s);
        return inCheck(root2, s);
    }
private:
    void inorder(TreeNode* root, int target, unordered_set<int>& s) {
        if (!root) return;
        inorder(root->left, target, s);
        s.insert(target - root->val);
        inorder(root->right, target, s);
    }
    
    bool inCheck(TreeNode* root, unordered_set<int>& s) {
        if (!root) return false;
        return inCheck(root->left, s) || s.find(root->val) != s.end() || inCheck(root->right, s);
    }
};
