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
    vector<double> averageOfLevels(TreeNode* root) {
        assert(root != nullptr);
        
        vector<double> averages;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            long sum = 0, count = 0;
            queue<TreeNode*> temp;
            
            while (!q.empty()) {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                ++count;
                if (curr->left) temp.push(curr->left);
                if (curr->right) temp.push(curr->right);
            }
            
            q = temp;
            averages.push_back(sum / double{count});
        }
            
        return averages;
    }
};
