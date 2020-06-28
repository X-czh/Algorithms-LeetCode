// Time complexity: O(h).
// Space complexity: O(h) extra space.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        assert(p && q);
        
        if (p->val < q->val) {
            return lowestCommonAncestorHelper(root, p->val, q->val);
        } else {
            return lowestCommonAncestorHelper(root, q->val, p->val);
        }
        
        return nullptr;
    }
private:
    TreeNode* lowestCommonAncestorHelper(TreeNode* root, int small, int large) {
        if (!root) return nullptr;
        
        int val = root->val;
        if (small <= val && large >= val) {
            return root;
        }
        if (small > val) {
            return lowestCommonAncestorHelper(root->right, small, large);
        }
        if (large < val) {
            return lowestCommonAncestorHelper(root->left, small, large);
        }
        
        return nullptr;
    }
};
