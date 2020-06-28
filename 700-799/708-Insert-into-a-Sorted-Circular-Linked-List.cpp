// Time complexity: O(n).
// Space complexity: O(1).

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        // list.length = 0
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        // list.length = 1
        if (head->next == head) {
            auto new_node = new Node(insertVal, head);
            head->next = new_node;
            return head;
        }
        
        auto prev = head;
        auto curr = head->next;
        do {
            if (// inserted in the middle 
                (curr->val >= insertVal && insertVal >= prev->val) ||
                // inserted at the begining or in the end
                (curr->val < prev->val && (insertVal <= curr->val || insertVal >= prev->val))) {
                auto new_node = new Node(insertVal, curr);
                prev->next = new_node;
                return head;
            }
            prev = curr;
            curr = curr->next;
        } while (prev != head);

        // corner case: all nodes in the list have the same value
        prev->next = new Node(insertVal, curr);
        return head;
    }
};
