// Time complexity: O(N)
// Space complexity: O(H)

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            if (node) {
                if (L <= node->val && node->val <= R) {
                    sum += node->val;
                }
                if (L < node->val) {
                    stk.push(node->left);
                }
                if (node->val < R) {
                    stk.push(node->right);
                }
            }
        }
        return sum;
    }
};
