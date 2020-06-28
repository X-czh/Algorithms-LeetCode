// Time complexity: O(l1.length + l2.length).
// Space complexity: O(1) auxiliary space.

/*
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy{};
        ListNode* prev = &dummy;
        ListNode* curr = nullptr;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr = new ListNode{l1->val};
                l1 = l1->next;
            } else {
                curr = new ListNode{l2->val};
                l2 = l2->next;
            }
            prev->next = curr;
            prev = curr;
        }
        while (l1) {
            curr = new ListNode{l1->val};
            l1 = l1->next;
            prev->next = curr;
            prev = curr;
        }
        while (l2) {
            curr = new ListNode{l2->val};
            l2 = l2->next;
            prev->next = curr;
            prev = curr;
        }
        
        return dummy.next;
    }
};
