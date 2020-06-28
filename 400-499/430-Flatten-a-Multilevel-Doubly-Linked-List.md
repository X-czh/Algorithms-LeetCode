# 430-Flatten a Multilevel Doubly Linked List

[Problem](https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/)

## Approach 1: Stack

The idea is to recursively flatten the list. In the recursive procedure, when a node has child, we flatten its child list first, and then insert the flattened child list after its parent node. The two state variables are the parent node and the next of the parent node between which we insert the flattened child list. The parent node part is easy, we simply append the head of the child list directly to the parent node. For the the next of the parent node, we use a stack to keep track of it.

Time complexity: O(n).

Space complexity: O(n).

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;

        Node* curr = head;
        while (curr) {
            if (curr->child) {
                if (curr->next) {
                    s.push(curr->next);
                }
                curr->child->prev = curr;
                curr->next = curr->child;
                curr->child = nullptr;
            } else if (!curr->next && !s.empty()) {
                Node* node = s.top();
                s.pop();
                node->prev = curr;
                curr->next = node;
            }
            curr = curr->next;
        }

        return head;
    }
};
```

## Approach 2: Link a node's next to the end of its child list

We can further eliminate the usage of stack. We know the next of the parent node shall be appended to the end of the parent node's flattened child list. We can manully iterate the unflattened child list and append the next of the parent node to the last node of the list. The fact that the child list is unflattened doesn't matter as we will go on to flatten it later, and it is guaranteed that all the newly flattened nodes are inserted before the next of the parent node.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    Node* flatten(Node* head) {
        for (auto curr = head; curr; curr = curr->next) {
            if (!curr->child) {
                continue;
            }
            auto curr_next = curr->next;
            curr->child->prev = curr;
            curr->next = curr->child;
            auto last_child = curr;
            while (last_child->next) {
                last_child = last_child->next;
            }
            if (curr_next) {
                last_child->next = curr_next;
                curr_next->prev = last_child;
            }
            curr->child = nullptr;
        }
        return head;
    }
};
```
