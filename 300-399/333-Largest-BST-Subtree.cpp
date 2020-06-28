// Time complexity: O(n).
// Space complexity: O(n).

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
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return maxBST_size;
    }
private:
    int maxBST_size = 0;
    
    vector<int> dfs(TreeNode* root) {
        int size = -1;
        int min_num = root->val;
        int max_num = root->val;
        
        vector<int> left{0, numeric_limits<int>::min(), numeric_limits<int>::min()};
        if (root->left) {
            left = dfs(root->left);
            min_num = min(min_num, left[1]);
            max_num = max(max_num, left[2]);
        }

        vector<int> right{0, numeric_limits<int>::max(), numeric_limits<int>::max()};
        if (root->right) {
            right = dfs(root->right);
            min_num = min(min_num, right[1]);
            max_num = max(max_num, right[2]);
        }
    
        // isBST?
        if (left[0] >= 0 && left[2] < root->val && right[0] >= 0 && right[1] >= root->val) {
            size = left[0] + right[0] + 1;
            maxBST_size = max(maxBST_size, size);
        }

        return {size, min_num, max_num};
    }
};


// Optimized a bit
class Solution2 {
public:
    int largestBSTSubtree(TreeNode* root) {
        int min_num = numeric_limits<int>::max();
        int max_num = numeric_limits<int>::min();
        int maxBST = 0;
        helper(root, min_num, max_num, maxBST);
        return maxBST;
    }
private:
    bool helper(TreeNode* root, int& min_num, int& max_num, int& maxBST) {
        if (!root) {
            return true;
        }

        int left_min = numeric_limits<int>::max();
        int left_max = numeric_limits<int>::min();
        int left_maxBST = 0;
        bool left_BST = helper(root->left, left_min, left_max, left_maxBST);

        int right_min = numeric_limits<int>::max();
        int right_max = numeric_limits<int>::min();
        int right_maxBST = 0;
        bool right_BST = helper(root->right, right_min, right_max, right_maxBST);
    
        min_num = min(root->val, min(left_min, right_min));
        max_num = max(root->val, max(left_max, right_max));
        if (left_BST && (!root->left || left_max < root->val) && 
            right_BST && (!root->right || right_min >= root->val)) {
            maxBST = left_maxBST + right_maxBST + 1;
            return true;
        } else {
            maxBST = max(left_maxBST, right_maxBST);
            return false;
        }
    }
};
