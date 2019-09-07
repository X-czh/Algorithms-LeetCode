// Time complexity: O(n).
// Space complexity: O(n).

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        queue<Node*> q;
        unordered_map<Node*, int> depth;
        
        Node* prev = nullptr;
        q.push(root);
        depth[root] = 0;
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            Node* left = curr->left;
            Node* right = curr->right;
            if (left) {
                q.push(left);
                depth[left] = depth[curr] + 1;
            }
            if (right) {
                q.push(right);
                depth[right] = depth[curr] + 1;
            }
            
            // update next
            if (prev && depth[prev] == depth[curr]) {
                prev->next = curr;
            }
            prev = curr;
        }
        
        return root;
    }
};