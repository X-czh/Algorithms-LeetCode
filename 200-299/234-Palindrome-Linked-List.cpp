// Time complexity: O(n).
// Space complexity: O(1).

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
    bool isPalindrome(ListNode* head) {
        // Reverse the first half list
        ListNode *reverse = nullptr, *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next; // must before slow->next is changed
            auto slow_next_tmp = slow->next;
            slow->next = reverse;
            reverse = slow;
            slow = slow_next_tmp;
        }

        if (fast) slow = slow->next; // if odd num of elements, jump over the center

        // Compare the two half
        while (reverse && slow) {
            if (reverse->val != slow->val) {
                return false;
            }
            reverse = reverse->next;
            slow = slow->next;
        }

        return true;
    }
};
