// Hash map for access by key, doubly-linked list to maintain the ordering in most recent access time. 
// Time complexity: O(1) both for put and get.
// Space complexity: O(capacity).

class DLinkedNode {
public:
    int key;
    int value;
    DLinkedNode* prev;
    DLinkedNode* next;
    
    DLinkedNode() = default;
    DLinkedNode(int k, int v) : key(k), value(v) { }
};

class LRUCache {
public:
    LRUCache(int capacity) : size_(0), capacity_(capacity) {
        head_ = new DLinkedNode{};
        tail_ = new DLinkedNode{};
        head_->next = tail_;
        tail_->prev = head_;
    }
    
    int get(int key) {
        auto found = cache_.find(key);
        
        if (found == cache_.end()) {
            return -1;
        }
        
        DLinkedNode* node = found->second;
        moveToHead(node); // move the accessed node to the head
        return node->value;
    }
    
    void put(int key, int value) {
        auto found = cache_.find(key);
        if (found != cache_.end()) {
            // update the value
            DLinkedNode* node = found->second;
            node->value = value;
            moveToHead(node); // move the updated node to the head
            return;
        }
        
        DLinkedNode* new_node = new DLinkedNode{key, value};
        cache_.emplace(key, new_node);
        addToHead(new_node);
        size_++;
        
        if (size_ > capacity_) {
            DLinkedNode* tail = popTail();
            cache_.erase(tail->key);
            delete tail; // release memory
            size_--;
        }
    }
private:
    // Add the new node right after head.
    void addToHead(DLinkedNode* node) {
        node->prev = head_;
        node->next = head_->next;
        head_->next->prev = node;
        head_->next = node;
    }
    
    // Remove an existing node from the linked list.
    void removeNode(DLinkedNode* node) {
        DLinkedNode* prev = node->prev;
        DLinkedNode* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    // Move certain node in between to the head.
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }
    
    // Pop the current tail.
    DLinkedNode* popTail() {
        DLinkedNode* res = tail_->prev;
        removeNode(res);
        return res;
    }
    
    int size_;
    int capacity_;
    unordered_map<int, DLinkedNode*> cache_;
    DLinkedNode* head_;
    DLinkedNode* tail_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
