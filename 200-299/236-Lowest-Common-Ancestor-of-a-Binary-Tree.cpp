// Time complexity: O(n).
// Space complexity: O(n) extra space.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        DFS(root, p, q);
        return answer;
    }
private:
    TreeNode* answer;

    bool DFS(TreeNode* curr, TreeNode* p, TreeNode* q) {
        if (!curr) {
            return false;
        }
        
        int left = DFS(curr->left, p, q) ? 1 : 0;
        int right = DFS(curr->right, p, q) ? 1 : 0;
        int mid = (curr == p || curr == q) ? 1 : 0;
        if (mid + left + right >= 2) {
            answer = curr;
        }
        
        return (mid + left + right > 0);
    }
};
