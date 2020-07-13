// Time complexity: O(n).
// Space complexity: O(n).

/**
 * Each node would have a 2-dimensional index (denoted as <column, row>)
 * Order nodes by column first, and for the nodes on the same column, 
 *  order them vertically based on their row indices.
 */

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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> vertical_order;
        unordered_map<int, vector<int>> col_map;
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        
        int col = 0;
        int min_col = 0;
        int max_col = 0;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            auto curr = p.first;
            auto col = p.second;
            col_map[col].push_back(curr->val);
            min_col = min(min_col, col);
            max_col = max(max_col, col);
            if (curr->left) {
                q.push(make_pair(curr->left, col - 1));
            }
            if (curr->right) {
                q.push(make_pair(curr->right, col + 1));
            }
        }
        
        for (int i = min_col; i <= max_col; i++) {
            vertical_order.push_back(col_map[i]);
        }
        return vertical_order;
    }
};
