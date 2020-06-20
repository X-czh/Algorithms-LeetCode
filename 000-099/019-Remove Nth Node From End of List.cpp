// Time complexity: O(n)
// Space complexity: O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy_head = ListNode(-1, head);
        auto slow = &dummy_head;
        auto fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        auto to_delete = slow->next;
        slow->next = to_delete->next;
        delete to_delete;

        return dummy_head.next;
    }
};
