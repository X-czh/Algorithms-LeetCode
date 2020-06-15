# 155-Min Stack

[Problem](https://leetcode.com/problems/min-stack/)

## Approach 1: Stack + MinHeap (pop is not constant time)

Time complexity: pop() is O(logn), others are O(1).

Space complexity: O(n).

```c++
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        pq.push(x);
    }
    
    void pop() {
        if (stk.top() == pq.top()) {
            pq.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return pq.top();
    }
private:
    stack<int> stk;
    priority_queue<int, vector<int>, std::greater<int>> pq;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

## Approach 2: Two Stacks

Use two Stacks. The main Stack should keep track of the order numbers arrived (a standard Stack), and the second Stack should keep track of the current minimum.

Time complexity: all operations are O(1).

Space complexity: O(n).

```c++
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data_stk.push(x);
        if (min_stk.empty() || x <= min_stk.top()) {
            min_stk.push(x);
        }
    }
    
    void pop() {
        if (data_stk.top() == min_stk.top()) {
            min_stk.pop();
        }
        data_stk.pop();
    }
    
    int top() {
        return data_stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
private:
    stack<int> data_stk;
    stack<int> min_stk;
};
```
