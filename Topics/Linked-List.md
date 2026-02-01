# Linked List

## Iterating through the list

**Approach 1:**

```c++
auto curr = head;
while (curr) {
    // do things
    curr = curr->next;
}
```

**Approach 2:**

```c++
for (auto curr = head; curr; curr = curr->next) {
    // do things
}
```

## Fast and slow pointers

**Example 1:** [876-Middle of the Linked List](../800-899/876-Middle-of-the-Linked-Lists.md).

The fast pointer runs twice as fast as the slow pointer. When the fast reaches the end, the slow reaches the middle. Can be extened to one-xth of the linked list.

```c++
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```

**Example 2:** [141-Linked List Cycle](../100-199/141-Linked-List-Cycle.md).

The Tortoise and the Hare: the hare will meet the torroise again as the route is cyclic.

```c++
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}
```

Also see [142-Linked List Cycle II](../100-199/142-Linked-List-Cycle-II.md).

**Example 3:** [160-Intersection of Two Linked Lists](../100-199/160-Intersection-of-Two-Linked-Lists.md).

Two Pointers—Crossover Loop: The trick of this crossover loop is to ensure that the two pointers arrive at the intersection node (if have) the second time at the same time (by that time, both travel the distance of A-only-part + B-only-part + intersection-part). If the two lists have no intersection, then the last nodes of them do not coincide.

```c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pA = headA, *pB = headB;

    while (pA || pB) {
        if (pA == pB) return pA;  
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }

    return nullptr;
}
```

## Memory Leakage

Potential memory leakage will occur when you try to use dummy nodes.

```c++
// Need to be mannually deallocated!
ListNode* dummy_head_ptr = new ListNode();

// Good practice, C++'s RAII will take care of the memory.
ListNode dummy_head;
ListNode* &dummy_head_ptr;
```
