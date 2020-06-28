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
    int longestUnivaluePath(TreeNode* root) {
        max_len = 0;
        postorder(root);
        return max_len;
    }
private:
    int max_len;

    // returns longest univalue path that ends at root
    int postorder(TreeNode* root) {
        if (!root) return 0;

        int left = postorder(root->left);
        int right = postorder(root->right);
        
        int res = 0;
        if (root->left && root->val == root->left->val) {
            res = max(res, left + 1);
        }
        if (root->right && root->val == root->right->val) {
            res = max(res, right + 1);
        }
        max_len = max(max_len, res);

        if (root->left && root->right &&
            root->val == root->right->val && root->val == root->left->val) {
            max_len = max(max_len, left + right + 2);
        }

        return res;
    }
};

// slightly polished
class Solution2 {
public:
    int longestUnivaluePath(TreeNode* root) {
        max_len = 0;
        postorder(root);
        return max_len;
    }
private:
    int max_len;

    // returns longest univalue path that ends at root
    int postorder(TreeNode* root) {
        if (!root) return 0;

        int left = postorder(root->left);
        int right = postorder(root->right);
        
        int arrow_left = 0;
        int arrow_right = 0;
        if (root->left && root->val == root->left->val) {
            arrow_left = left + 1;
        }
        if (root->right && root->val == root->right->val) {
            arrow_right = right + 1;
        }
    
        max_len = max(max_len, arrow_left + arrow_right);
        return max(arrow_left, arrow_right);
    }
};
