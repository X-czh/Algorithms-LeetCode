# 138-Copy List with Random Pointer

[Problem](https://leetcode.com/problems/copy-list-with-random-pointer/)

## Approach 1: Hash Table

The main difficulty of this problem is how to copy the next and random ptrs of the node. When copying the two ptrs, we need access to the copies of the original nodes to which the two ptrs points. A straightforward way to gain the access is to create a hash map storing the pairs of the original nodes and their copies.

Time complexity: O(n).

Space complexity: O(n).

```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> m;

        // Copy head and store in map
        Node* copy_head = new Node(head->val, nullptr, nullptr);
        m.insert({head, copy_head});

        // Copy the rest nodes and store in map
        for (auto node = head->next; node; node = node->next) {
            Node* copy_node = new Node(node->val, nullptr, nullptr);
            m.insert({node, copy_node});
        }

        // Copy next and random ptrs using the map
        for (auto node = head; node; node = node->next) {
            (m[node])->next = m[node->next];
            (m[node])->random = m[node->random];
        }

        return copy_head;
    }
};
```

## Approach 2: Put the copied node after the original one

Hash map requires additional space. Another way to gain the access is to simply put the copied node after the original one. Like this: NODE1 -> COPY_NODE1 - >NODE2 -> COPY_NODE2 -> NULL. After we copy the random ptrs, we can then seperate the copied nodes from original ones.

Time complexity: O(n).

Space complexity: O(1).

```c++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Insert the copied node after the original one
        for (auto curr = head; curr; curr = curr->next->next) {
            Node* copy = new Node{curr->val, curr->next, nullptr};
            curr->next = copy;
        }

        // Update random node
        for (auto curr = head; curr; curr = curr->next->next) {
            Node* copy = curr->next;
            if (curr->random) {
                copy->random = curr->random->next;
            }
        }

        // Seperate the copied nodes from original ones
        Node dummy{-1, head, nullptr};
        for (auto copy = &dummy, curr = head; curr; curr = curr->next, copy = copy->next) {
            copy->next = copy->next->next;
            curr->next = curr->next->next;
        }

        return dummy.next;
    }
};
```
