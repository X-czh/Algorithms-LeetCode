# 295-Find Median from Data Stream

[Problem](https://leetcode.com/problems/find-median-from-data-stream/)

## Approach 1: Sort when findMedian

Time complexity: O(1) for addNum, O(NlogN) for findMedian.

Space complexity: O(N) auxiliary space.

## Approach 2: Insertion sort on the way

Time complexity: O(logN + N) = O(N) with vector (O(logN) for binary search of insertion position, O(N) for shifting elements during insertion) OR O(N) with linked list for addNum, O(1) for findMedian.

Space complexity: O(N) auxiliary space.

## Approach 3: Two Heaps

Use a min heap to store the higher half of the stream, and a max heap to store the lower half of the stream. The top elements of the heaps will be in the middle.

Time complexity: O(logN) for addNum, O(1) for findMedian.

Space complexity: O(N) auxiliary space.

```c++
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (pq_low.empty() || num < pq_low.top()) {
            pq_low.push(num);
        } else {
            pq_high.push(num);
        }
        
        // balance low and high parts
        if (pq_low.size() < pq_high.size()) {
            pq_low.push(pq_high.top());
            pq_high.pop();
        } else if (pq_low.size() - 1 > pq_high.size()) {
            pq_high.push(pq_low.top());
            pq_low.pop();
        }
    }
    
    double findMedian() {
        return (pq_low.size() > pq_high.size()) ?
            static_cast<double>(pq_low.top()) :
            (pq_low.top() + pq_high.top()) * 0.5;
    }
private:
    priority_queue<int> pq_low; // max heap for low values
    priority_queue<int, vector<int>, greater<int>> pq_high; // min heap for high values
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

Another implementation with shorter code but runs slower due to extra heap operations:

```c++
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        pq_low.push(num);

        pq_high.push(pq_low.top());
        pq_low.pop();
        
        // balance low and high parts
        if (pq_low.size() < pq_high.size()) {
            pq_low.push(pq_high.top());
            pq_high.pop();
        }
    }
    
    double findMedian() {
        return (pq_low.size() > pq_high.size()) ?
            static_cast<double>(pq_low.top()) :
            (pq_low.top() + pq_high.top()) * 0.5;
    }
private:
    priority_queue<int> pq_low; // max heap for low values
    priority_queue<int, vector<int>, greater<int>> pq_high; // min heap for high values
};
```

## Approach 4: Self-balancing Binary Search Trees

Time complexity: O(logN) for addNum, O(1) for findMedian.

Space complexity: O(N) auxiliary space.

TODO
