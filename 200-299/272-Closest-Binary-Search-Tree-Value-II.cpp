// Time complexity: O(n).
// Space complexity: O(n) extra space.

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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;

        // inorder traversal -> sorted array
        vector<int> lst;
        inorder(root, lst);
        
        // hi: first point s.t. lst[hi] > target
        // lo: last point s.t. lst[lo] <= target
        int hi = 0;
        while (hi < lst.size() && lst[hi] <= target) {
            hi++;
        }
        int lo = hi - 1;
        
        // two pointers to find k closest values
        for (int i = 0; i < k; i++) {
            if (lo < 0) {
                res.push_back(lst[hi]);
                hi++;
            } else if (hi > lst.size() - 1) {
                res.push_back(lst[lo]);
                lo--;
            } else {
                if (abs(lst[lo] - target) < abs(lst[hi] - target)) {
                    res.push_back(lst[lo]);
                    lo--;
                } else {
                    res.push_back(lst[hi]);
                    hi++;
                }
            }
        }

        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& lst) {
        if (!root) return;

        inorder(root->left, lst);
        lst.push_back(root->val);
        inorder(root->right, lst);
    }
};
