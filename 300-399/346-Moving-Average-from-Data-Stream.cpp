// Time complexity: O(1) for next.
// Space complexity: O(qsize) extra space.

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : sum(0), qsize(size) { }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > qsize) {
            sum -= q.front();
            q.pop();
        }
        return static_cast<double>(sum) / q.size();
    }
private:
    int sum;
    int qsize;
    queue<int> q;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
 