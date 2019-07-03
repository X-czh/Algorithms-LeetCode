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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        // Count list length
        int list_len{0};
        for (auto node = root; node; node = node->next) list_len++;

        // Calculate base part length and remainder
        int part_len_base{list_len / k};
        int remainder{list_len % k};

        vector<ListNode*> v{};
        ListNode* curr{root};
        ListNode* prev{nullptr};
        for (auto i = 0; i < k; ++i) {
            ListNode* head{curr};

            int part_len{part_len_base + ((i < remainder) ? 1 : 0)};
            for (auto j = 0; j < part_len; ++j) {
                prev = curr;
                curr = curr->next;
            }
            if (prev) prev->next = nullptr; // tricky part, prev of first sublist is nullptr

            v.push_back(head);
        }

        return v;
    }
};