# Monotonic Stack & Queue

## Monotonic Stack

### Definition

A monotonic stack is a stack with its elements ordered monotonically. Specificly, it maintains the monotonicity by popping elements when a new element e is pushed into the stack.

### Usage

Monotonic stacks are best suited for problems that requires finding the next/previous greater/smaller element in a list of elements. You just iterate through the list and push elements into the stack. The top element in the stack right before the new element is actually pushed into the stack is the next/previous greater/smaller element of the pushed element. The complexity of doing so for each element in the list is **linear**.

* For **greater** problems, use a monotonically **increasing** stack (from top to bottom).
* For **smaller** problems, use a monotonically **decreasing** stack (from top to bottom).
* For **next** problems, **backwardly** iterate through the list and push elements into the stack.
* For **previous** problems, **forwardly** iterate through the list.
* For problems with a **circular** list, iterate through the list **twice**.

### Implementation

Default: nonstrictly monotonically decreasing stack.

```c++
template <typename T, typename Compare = std::less<T>>
class MonotonicStack {
public:
    MonotonicStack() { }

    MonotonicStack(const Compare& compare) : cmp(compare) { }

    bool empty() {
        return s.empty();
    }

    T top() {
        return s.top();
    }

    void push(T e) {
        while (!s.empty() && cmp(e, s.top()) {
            s.pop();
        }
        s.push(e);
    }

    void pop() {
        s.pop();
    }
private:
    stack<T> s;
    Compare cmp;
};
```

### Problems

* Basic: [496-Next Greater Element I](../400-499/496-Next%20Greater%20Element%20I.cpp) and [1019-Next Greater Node In Linked List](../1000-1099/1019-Next%20Greater%20Node%20In%20Linked%20List.md).
* Dealing with circular list: [503-Next Greater Element II](../500-599/503-Next%20Greater%20Element%20II.cpp).
* Variant: [042-Trapping Rain Water](../000-099/049-Trapping%20Rain%20Water%20.md).
* Variant: [084-Largest Rectangle in Histogram](../000-099/084-Largest%20Rectangle%20in%20Histogram.md).

## Monotonic Queue

### Definition

A monotonic queue is a queue with its elements ordered monotonically. Specificly, it maintains the monotonicity by dequeuing elements when a new element e is enqueued, while a priority queue maintains the monotonicity by sorting/heapifying when a new element e is enqueued.

### Usage

### Implementation

Default: nonstrictly monotonically increasing queue.

```c++
template <typename T, typename Compare = std::less<T>>
class MonotonicQueue {
public:
    MonotonicQueue() { }

    MonotonicQueue(const Compare& compare) : cmp(compare) { }

    bool empty() {
        return q.empty();
    }

    T front() {
        return q.front();
    }

    void push(T e) {
        while (!q.empty() && cmp(e, s.back()) {
            q.pop_back();
        }
        q.push_back(e);
    }

    void pop(T e) {
        if (!q.empty() && q.front() == e)
            q.pop_front();
    }
private:
    deque<T> q;
    Compare cmp;
};
```

### Problems
