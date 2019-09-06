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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        out(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return in(iss);
    }
    
private:
    void out(TreeNode* node, ostringstream& oss) {
        if (!node) {
            oss << "# ";
            return;
        }
        oss << node->val << " ";
        out(node->left, oss);
        out(node->right, oss);
    }
    
    TreeNode* in(istringstream& iss) {
        string str;
        iss >> str;
        if (str == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(str));
        node->left = in(iss);
        node->right = in(iss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
