// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

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
// Space complexity: O(n).

// Use the same encoding as LeetCode, e.g. "[1, 2, 3, null, null, 4]"
class Codec1 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        
        string str{"[" + to_string(root->val)};
        
        queue<TreeNode*> q;
        q.push(root);
        int non_null_count = 1;
        
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            
            if (curr) {
                --non_null_count;
                if (curr != root) {
                    str += "," + to_string(curr->val);
                }
                
                auto left = curr->left;
                q.push(left);
                if (left) ++non_null_count;
                
                auto right = curr->right;
                q.push(right);
                if (right) ++non_null_count;
            } else if (non_null_count > 0) {
                str += ",null";
            }
        }
        
        str += "]";
        
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 2) return nullptr; // "[]"
        
        TreeNode* root;
        queue<TreeNode*> q;
        
        // create root node
        int start = 1;
        int end = start + 1;
        while (data[end] != ',' && data[end] != ']') ++end;
        string val_str = data.substr(start, end - start);
        if (val_str == "null") { // "[null]"
            return nullptr;
        } else {
            int val = stoi(val_str, nullptr);
            root = new TreeNode{val};
            q.push(root);
        }
        
        
        // create the rest of the nodes
        start = end + 1;
        while (start < data.size() - 1) {
            TreeNode* curr = q.front();
            q.pop();
            
            // create left subnode
            end = start + 1;
            while (end < data.size() && data[end] != ',' && data[end] != ']') ++end;
            if (end >= data.size()) break;
            val_str = data.substr(start, end - start);
            if (val_str != "null") {
                int val = stoi(val_str, nullptr);
                TreeNode* node = new TreeNode{val};
                curr->left = node;
                q.push(node);
            }
            start = end + 1;
            
            // create right subnode
            end = start + 1;
            while (end < data.size() && data[end] != ',' && data[end] != ']') ++end;
            if (end >= data.size()) break;
            val_str = data.substr(start, end - start);
            if (val_str != "null") {
                int val = stoi(val_str, nullptr);
                TreeNode* node = new TreeNode{val};
                curr->right = node;
                q.push(node);
            }
            start = end + 1;
        }
        
        return root;
    }
};

// Use a different encoding from LeetCode, utilizing C++'s ostringstream and istringstream.
// e.g. "1 2 # # 3 4 # # # "
class Codec2 {
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
