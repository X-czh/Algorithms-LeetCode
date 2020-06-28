# 703-Kth Largest Element in a Stream

[Problem](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

## Approach: Min Heap

We use a min heap of fixed size K to store the K largest elements in the stream. Specificly, the Kth largest element will be at the top of the heap. It is unintuitive to maintain the K "largest" values with a "min" heap. However, by keeping the min heap fixed-size (whenever we see a value that is larger than the miminum of the heap values, we replace it with the minimum value), we effectively keeps the largest elements in the heap, and drops the smaller ones. The structure of min heap further allows us to retrieve the smallest element of the heap, which is exactly the Kth largest element in constant time.

Time complexity: O(logK) for add.

Space complexity: O(K) auxiliary space.

```c++
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : size(k) {
        for (auto num : nums) {
            pq.push(num);
            if (pq.size() > size) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > size) {
            pq.pop();
        }
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    int size;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```
