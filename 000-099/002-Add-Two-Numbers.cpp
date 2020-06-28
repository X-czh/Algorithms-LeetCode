// len(l1) = m, len(l2) = n.
// Time complexity: O(max(m, n)).
// Space complexity: O(max(m, n)).

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy_head{new ListNode{0}};
        ListNode *p{l1}, *q{l2}, *curr{dummy_head};
        int carry{0};
        
        while (p || q) {
            int x{(p) ? p->val : 0};
            int y{(q) ? q->val : 0};
            int sum{carry + x + y};
            carry = sum / 10;
            curr->next = new ListNode{sum % 10};
            curr = curr->next;
            if (p) p = p->next;
            if (q) q = q->next;
        }
        if (carry > 0) {
            curr->next = new ListNode{carry};
        }
            
        return dummy_head->next;
    }
};
