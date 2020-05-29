// Time complexity: O(n)
// Space complexity: O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive Solution 1
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        vector<int> inorder;
        
        auto inorder_left = inorderTraversal(root->left);
        inorder.insert(inorder.end(), inorder_left.begin(), inorder_left.end());
        
        inorder.push_back(root->val);
        
        auto inorder_right = inorderTraversal(root->right);
        inorder.insert(inorder.end(), inorder_right.begin(), inorder_right.end());
        
        return inorder;
    }
};

// Recursive Solution 2
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
private:
    void helper(TreeNode* root, vector<int>& result) {
        if (root) {
            helper(root->left, result);
            result.push_back(root->val);
            helper(root->right, result);
        }
    } 
};

// Iterative Solution
class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while (curr || !s.empty()) {
            // go left as far as possible
            while (curr) {
                s.push(curr);
                curr = curr->left;
            }
            
            // add the root
            curr = s.top();
            s.pop();
            inorder.push_back(curr->val);

            // turn right
            curr = curr->right;
        }
        
        return inorder;
    }
};
