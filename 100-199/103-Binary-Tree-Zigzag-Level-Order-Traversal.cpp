// Time complexity: O(n).
// Space complexity: O(n).

// Utilizies deque

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        deque<TreeNode*> node_q;
        deque<int> depth_q;
        vector<vector<int>> zigzag_level_order;
        node_q.push_back(root);
        depth_q.push_back(0);
        
        bool left_to_right = true;
        while (!node_q.empty()) {
            TreeNode* node;
            int depth;
            
            if (left_to_right) {
                node = node_q.front();
                node_q.pop_front();
                depth = depth_q.front();
                depth_q.pop_front();
    
                if (node->left) {
                    node_q.push_back(node->left);
                    depth_q.push_back(depth + 1);
                }
                if (node->right) {
                    node_q.push_back(node->right);
                    depth_q.push_back(depth + 1);
                }
            } else {
                node = node_q.back();
                node_q.pop_back();
                depth = depth_q.back();
                depth_q.pop_back();
                
                if (node->right) {
                    node_q.push_front(node->right);
                    depth_q.push_front(depth + 1);
                }
                if (node->left) {
                    node_q.push_front(node->left);
                    depth_q.push_front(depth + 1);
                }
            }
            
            if (depth + 1 > zigzag_level_order.size()) {
                zigzag_level_order.push_back(vector<int>{});
            }
            zigzag_level_order[depth].push_back(node->val);
            
            if (node_q.empty() || 
                (left_to_right && depth_q.front() > depth) || 
                (!left_to_right && depth_q.back() > depth)) {
                left_to_right = !left_to_right;
            }
        }
        
        return zigzag_level_order;
    }
};
