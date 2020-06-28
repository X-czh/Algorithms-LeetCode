// Time complexity: O(n). Visited each node once.
// Space complexity: O(n) due to recursion.

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
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int intermediate = 0, sum = 0;
        sumNumbersRecu(root, intermediate, &sum);
        return sum;
    }
private:
    void sumNumbersRecu(TreeNode* root, int intermediate, int* sum) {
        int new_intermediate = intermediate * 10 + root->val;
        if (!root->left && !root->right) {
            (*sum) += new_intermediate;
        } else {
            if (root->left) {
                sumNumbersRecu(root->left, new_intermediate, sum);
            }
            if (root->right) {
                sumNumbersRecu(root->right, new_intermediate, sum);
            }
        }
    }
};
