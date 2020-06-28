// Similar logic of 105 applies here. See 105.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time complexity: O(n).
// Space complexity: O(n) extra space due to recursion.

class Solution1 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_idx = postorder.size() - 1;
        return buildTreeRecu(inorder, postorder, 0, inorder.size());
    }
private:
    int postorder_idx;
    
    TreeNode* buildTreeRecu(vector<int>& inorder, vector<int>& postorder, int inorder_start, int inorder_end) {
        if (inorder_start == inorder_end) return nullptr;
        
        TreeNode* root = new TreeNode{postorder[postorder_idx--]};
        
        if (inorder_start + 1 == inorder_end) return root;
        
        int inorder_root = inorder_start;
        while (inorder_root < inorder_end && inorder[inorder_root] != root->val) ++inorder_root;
        
        root->right = buildTreeRecu(inorder, postorder, inorder_root + 1, inorder_end);
        root->left = buildTreeRecu(inorder, postorder, inorder_start, inorder_root);
        
        return root;
    }
};

// Solution 2: Use Hash Map to store the position of the roots in inorder.
// Time complexity: O(n).
// Space complexity: O(n) extra space.

class Solution2 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_idx = postorder.size() - 1;
        unordered_map<int, int> inorder_value_idx_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_value_idx_map.emplace(inorder[i], i);
        }
        return buildTreeRecu(inorder, postorder, 0, inorder.size(), inorder_value_idx_map);
    }
private:
    int postorder_idx;
    
    TreeNode* buildTreeRecu(vector<int>& inorder, vector<int>& postorder, int inorder_start, int inorder_end, unordered_map<int, int> &inorder_value_idx_map) {
        if (inorder_start == inorder_end) return nullptr;
        
        TreeNode* root = new TreeNode{postorder[postorder_idx--]};
        
        if (inorder_start + 1 == inorder_end) return root;
        
        int inorder_root = inorder_value_idx_map[root->val];
        
        root->right = buildTreeRecu(inorder, postorder, inorder_root + 1, inorder_end, inorder_value_idx_map);
        root->left = buildTreeRecu(inorder, postorder, inorder_start, inorder_root, inorder_value_idx_map);
        
        return root;
    }
};
