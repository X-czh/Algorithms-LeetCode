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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy{-1};
        dummy.next = head;
        ListNode* prev{&dummy};
        ListNode* curr{head};
        
        // Iterate to position m
        for (int i{1}; i < m; ++i) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* pred_node_m{prev};
        ListNode* node_m{curr};
        
        // Reverse list between position m and n
        for (int i{0}; i < n - m + 1; ++i) {
            ListNode* next_temp{curr->next};
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        ListNode* node_n{prev};
        ListNode* succ_node_n{curr};
        
        // Combine lists
        pred_node_m->next = node_n;
        node_m->next = succ_node_n;

        return dummy.next;
    }
};
