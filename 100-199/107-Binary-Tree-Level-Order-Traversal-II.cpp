// Time complexity: O(n).
// Space complexity: O(n).

// Use a stack to flip over the list

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> node_q;
        queue<int> depth_q;
        node_q.push(root);
        depth_q.push(0);
        
        stack<vector<int>> s;
        while (!node_q.empty()) {
            TreeNode* node = node_q.front();
            node_q.pop();
            int depth = depth_q.front();
            depth_q.pop();
            
            if (depth + 1 > s.size()) {
                s.push(vector<int>{});
            }
            s.top().push_back(node->val);
            
            if (node->left) {
                node_q.push(node->left);
                depth_q.push(depth + 1);
            }
            if (node->right) {
                node_q.push(node->right);
                depth_q.push(depth + 1);
            }
        }
        
        vector<vector<int>> level_order;
        while (!s.empty()) {
            level_order.push_back(s.top());
            s.pop();
        }
        
        return level_order;
    }
};
