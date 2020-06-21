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
    int maxDepth(Node* root) {
        if (!root) return 0;

        int max_depth = 1;
        for (auto child : root->children) {
            max_depth = max(max_depth, maxDepth(child) + 1);
        }
        return max_depth;
    }
};
