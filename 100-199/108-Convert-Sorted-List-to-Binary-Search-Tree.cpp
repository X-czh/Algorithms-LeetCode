// Time complexity: O(n).
// Space complexity: O(logn) extra space due to recursion.

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTRecu(nums, 0, nums.size());
    }
private:
    TreeNode* sortedArrayToBSTRecu(const vector<int>& nums, int start, int end) {
        if (start == end) {
            return nullptr;
        } else {
            int mid = start + (end - start) / 2;
            TreeNode* root = new TreeNode{nums[mid]};
            root->left = sortedArrayToBSTRecu(nums, start, mid);
            root->right = sortedArrayToBSTRecu(nums, mid + 1, end);
            return root;
        }
    }
};
