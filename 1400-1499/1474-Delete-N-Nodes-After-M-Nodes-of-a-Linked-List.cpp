// Time complexity: O(n)
// Space complexity: O(1) extra space

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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        auto curr = head;
        while (true) {
            auto prev = curr;
            for (int i = 0; i < m; i++) {
                prev = curr;
                curr = curr->next;
                if (!curr)
                    return head;
            }
            prev->next = nullptr;
            for (int i = 0; i < n; i++) {
                curr = curr->next;
                if (!curr)
                    return head;
            }
            prev->next = curr;
        }
        return head;
    }
};
