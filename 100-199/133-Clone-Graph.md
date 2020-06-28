# 133-Clone Graph

[Problem](https://leetcode.com/problems/clone-graph/)

## Appraoch 1: DFS

Time complexity: O(V + E).

Space complexity: O(V + E).

### Solution 1: Recursive

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> cloned;
        return cloneGraphDFS(node, cloned);
    }
private:
    Node* cloneGraphDFS(Node* node, unordered_map<Node*, Node*>& cloned) {
        // cloned before, directly return
        if (cloned.find(node) != cloned.end()) return cloned[node];

        // clone curr node
        Node* node_clone = new Node{};
        node_clone->val = node->val;
        cloned.emplace(node, node_clone);

        // clone neighbors
        for (auto neighbor : node->neighbors) {
            node_clone->neighbors.push_back(cloneGraphDFS(neighbor, cloned));
        }

        return node_clone;
    }
};
```

### Solution 2: Iterative

```c++
class Solution {
public:
    Node* cloneGraph(Node* node) {
        stack<Node*> s;
        s.push(node);

        unordered_map<Node*, Node*> cloned;
        Node* node_clone = new Node{};
        node_clone->val = node->val;
        cloned.emplace(node, node_clone);

        while (!s.empty()) {
            Node* curr = s.top();
            s.pop();
            Node* curr_clone = cloned[curr];

            for (auto neighbor : curr->neighbors) {
                if (cloned.find(neighbor) == cloned.end()) {
                    s.push(neighbor);
                    Node* neighbor_clone = new Node{};
                    neighbor_clone->val = neighbor->val;
                    cloned.emplace(neighbor, neighbor_clone);
                }
                curr_clone->neighbors.push_back(cloned[neighbor]);
            }
        }

        return node_clone;
    }
};
```

## Approach 2: BFS

Time complexity: O(V + E).

Space complexity: O(V + E).

```c++
class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        q.push(node);

        unordered_map<Node*, Node*> cloned;
        Node* node_clone = new Node{};
        node_clone->val = node->val;
        cloned.emplace(node, node_clone);

        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();

            for (auto neighbor : curr->neighbors) {
                if (cloned.find(neighbor) == cloned.end()) {
                    q.push(neighbor);
                    Node* neighbor_clone = new Node{};
                    neighbor_clone->val = neighbor->val;
                    cloned.emplace(neighbor, neighbor_clone);
                }
                cloned[curr]->neighbors.push_back(cloned[neighbor]);
            }
        }

        return node_clone;
    }
};
```
