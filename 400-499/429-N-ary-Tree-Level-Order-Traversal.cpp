// Time complexity: O(n).
// Space complexity: O(n) extra space.

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
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return vector<vector<int>>{};
        }

        vector<vector<int>> res;

        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            auto node = p.first;
            auto level = p.second;
            if (level >= res.size()) {
                res.push_back({});
            }
            res[level].push_back(node->val);

            for (auto child : node->children) {
                q.push({child, level + 1});
            }
        }

        return res;
    }
};
