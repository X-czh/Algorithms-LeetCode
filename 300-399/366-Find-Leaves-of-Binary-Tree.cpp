// Time complexity: O(n).
// Space complexity: O(1)..

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* root, vector<vector<int>>& res){
        if (!root) return 0;
        int level = max(dfs(root->left, res), dfs(root->right, res)) + 1;
        if (level > res.size()) res.push_back(vector<int>());
        res[level - 1].push_back(root->val);
        return level;
    }
};
