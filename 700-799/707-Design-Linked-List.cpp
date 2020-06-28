// Time complexity:
//      init: O(1)
//      get: O(n)
//      addAtHead: O(1)
//      addAtTail: O(1)
//      addAtIndex: O(n)
//      deleteAtIndex: O(n)
// Space complexity: O(n)

struct Node {
    Node(int _val, Node* _prev, Node* _next)
        : val(_val), prev(_prev), next(_next) { }

    int val;
    Node* prev;
    Node* next;
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() : head(nullptr), tail(nullptr), len(0) { }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= len) {
            return -1;
        }

        auto curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        auto node = new Node(val, nullptr, head);
        if (head) {
            head->prev = node;
        } else {
            tail = node;
        }
        head = node;
        len++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        auto node = new Node(val, tail, nullptr);
        if (tail) {
            tail->next = node;
        } else {
            head = node;
        }
        tail = node;
        len++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0 || index > len) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == len) {
            addAtTail(val);
            return;
        }

        auto curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        auto node = new Node(val, curr->prev, curr);
        curr->prev->next = node;
        curr->prev = node;
        len++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) {
            return;
        }

        auto curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        if (curr->prev) {
            curr->prev->next = curr->next;
        }
        if (curr->next) {
            curr->next->prev = curr->prev;
        }

        if (curr == head) {
            head = head->next;
        }
        if (curr == tail) {
            tail = tail->prev;
        }
        delete curr;
        len--;
    }
private:
    Node* head;
    Node* tail;
    int len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
