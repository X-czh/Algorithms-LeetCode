# 1019-Next Greater Node In Linked List

[Problem](https://leetcode.com/problems/next-greater-node-in-linked-list/)

## Approach 1: Naive Search

Time complexity: O(n^2).

Space complexity: O(1) auxiliary space.

```c++
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result{};

        for (auto node_i = head; node_i; node_i = node_i->next) {
            int next_larger_value{0};
            int node_i_val{node_i->val};
            for (auto node_j = node_i; node_j; node_j = node_j->next) {
                if (node_j->val > node_i_val) {
                    next_larger_value = node_j->val;
                    break;
                }
            }
            result.push_back(next_larger_value);
        }

        return result;
    }
};
```

## Approach 2: Monotonic Stack

Time complexity: O(n).

Space complexity: O(n) auxiliary space.

```c++
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;

        for (ListNode* curr = head; curr; curr = curr->next) {
            ans.push_back(curr->val);
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            int num = ans[i];
            while (!s.empty() && num >= s.top()) {
                s.pop();
            }
            ans[i] = s.empty() ? 0 : s.top();
            s.push(num);
        }

        return ans;
    }
};
```
