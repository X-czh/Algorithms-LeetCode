// Time complexity: O(n). Visited each node once.
// Space complexity: O(n^2). At most O(2^(logn)) = O(n) paths, each path has at most O(n) nodes.

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) {
            return paths;
        }
        
        string intermediate;
        binaryTreePathsRecu(root, intermediate, paths);
        
        return paths;
    }
private:
    void binaryTreePathsRecu(TreeNode* root, string& intermediate, vector<string>& paths) {
        if (!root->left && !root->right) {
            string new_intermediate = intermediate + to_string(root->val);
            paths.push_back(new_intermediate);
        } else {
            string new_intermediate = intermediate + to_string(root->val) + "->";
            if (root->left) {
                binaryTreePathsRecu(root->left, new_intermediate, paths);
            }
            if (root->right) {
                binaryTreePathsRecu(root->right, new_intermediate, paths);
            }
        }
    }
};
