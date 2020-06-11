// Compare every k nodes (head of every linked list) and get the node with the smallest value using heap.
// Extend the final sorted linked list with the selected nodes.

// Time complexity: O(nlogk).
// Space complexity: O(k) for in-place solution here.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> heap(cmp);
        for (auto node : lists) {
            if (node) {
                heap.push(node);
            }
        }

        auto dummy_head = ListNode{-1};
        auto curr = &dummy_head;
        while (!heap.empty()) {
            auto node = heap.top();
            heap.pop();
            curr->next = node;
            if (node->next) {
                heap.push(node->next);
            }
            curr = curr->next;   
        }

        return dummy_head.next;
    }
};
