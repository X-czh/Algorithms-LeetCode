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

class Solution2 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> interm;
        dfs(root, sum, interm, res);
        return res;
    }
private:
    void dfs(TreeNode* root, int sum, vector<int>& interm, vector<vector<int>>& res) {
        if (!root) return;

        interm.push_back(root->val);
        if (!root->left && !root->right) {
            if (sum == root->val) {
                res.push_back(interm);
            }
        } else {
            dfs(root->left, sum - root->val, interm, res);
            dfs(root->right, sum - root->val, interm, res);
        }
        interm.pop_back();
    }
};
