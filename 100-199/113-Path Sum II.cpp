// Time complexity: O(n)
// Space complexity: O(n) due to recursion

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        
        if (!root) return result;
        if (!root->left && !root->right && sum == root->val) return {{root->val}};
        
        vector<vector<int>> left_path = pathSum(root->left, sum - root->val);
        vector<vector<int>> right_path = pathSum(root->right, sum - root->val);
        for (auto const& v : left_path) {
            vector<int> path{root->val};
            path.insert(path.end(), v.begin(), v.end());
            result.push_back(path);
        }
        for (auto const& v : right_path) {
            vector<int> path{root->val};
            path.insert(path.end(), v.begin(), v.end());
            result.push_back(path);
        }
        return result;
    }
};
