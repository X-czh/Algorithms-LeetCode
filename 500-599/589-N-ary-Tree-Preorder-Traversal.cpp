// Time complexity: O(n).
// Space complexity: O(h) extra space.

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};

        vector<int> res;

        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            res.push_back(node->val);
            for (auto i = node->children.rbegin(), e = node->children.rend(); i != e; ++i) {
                stk.push(*i);
            }
        }
        
        return res;
    }
};
