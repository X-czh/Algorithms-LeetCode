// Time complexity: O(n).
// Space complexity: O(n).

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> node_q;
        queue<int> depth_q;
        vector<vector<int>> level_order;
        node_q.push(root);
        depth_q.push(0);
        
        while (!node_q.empty()) {
            TreeNode* node = node_q.front();
            node_q.pop();
            int depth = depth_q.front();
            depth_q.pop();
            
            if (depth + 1> level_order.size()) {
                level_order.push_back(vector<int>{});
            }
            level_order[depth].push_back(node->val);
            
            if (node->left) {
                node_q.push(node->left);
                depth_q.push(depth + 1);
            }
            if (node->right) {
                node_q.push(node->right);
                depth_q.push(depth + 1);
            }
        }
        
        return level_order;
    }
};
