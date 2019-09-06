// Time complexity: O(n).
// Space complexity: O(2 * n) extra space.

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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        
        vector<int> largest_values;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        int max_value = root->val;
        int prev_depth = -1;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* curr = p.first;
            int curr_depth = p.second;
            
            if (curr_depth > 0 && curr_depth > prev_depth) { // start of a new row (excludes first row)
                largest_values.push_back(max_value);
                max_value = curr->val;
            }
            
            max_value = max(max_value, curr->val);
            if (curr->left) q.push({curr->left, curr_depth + 1});
            if (curr->right) q.push({curr->right, curr_depth + 1});
            prev_depth = curr_depth;
        }
        largest_values.push_back(max_value); // handles last row
        
        return largest_values;
    }
};
