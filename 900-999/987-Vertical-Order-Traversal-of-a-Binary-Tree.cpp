// BFS + Hash Map + Heap
// Time complexity: O(N * log W), where W is the max number of nodes in the same column.
// Space complexity: O(N).

/**
 * Each node would have a 2-dimensional index (denoted as <column, row>)
 * Order nodes by column first, 
 *  for the nodes on the same column, order them vertically based on their row indices,
 *  for the nodes on the same column and row, order them by value in ascending order
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> vertical_order;
        unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>>> col_map;
        
        queue<tuple<TreeNode*, int, int>> q;
        q.push(make_tuple(root, 0, 0));
        
        int min_col = 0;
        int max_col = 0;
        while (!q.empty()) {
            auto tup = q.front();
            q.pop();
            auto curr = std::get<0>(tup);
            auto col = std::get<1>(tup);
            auto row = std::get<2>(tup);
            col_map[col].push(make_pair(row, curr->val));
            min_col = min(min_col, col);
            max_col = max(max_col, col);
            if (curr->left) {
                q.push(make_tuple(curr->left, col - 1, row + 1));
            }
            if (curr->right) {
                q.push(make_tuple(curr->right, col + 1, row + 1));
            }
        }
        
        for (int i = min_col; i <= max_col; i++) {
            vector<int> vec;
            auto pq = col_map[i];
            while (!pq.empty()) {
                vec.push_back(pq.top().second);
                pq.pop();
            }
            vertical_order.push_back(vec);
        }
        return vertical_order;
    }
};
