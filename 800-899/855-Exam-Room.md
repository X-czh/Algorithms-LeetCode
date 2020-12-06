# 855-Exam Room

[Problem](https://leetcode.com/problems/exam-room/)

## BST

```c++
class Compare {
public:
    Compare(int N) : num(N) {}

    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        const int dist_a = distance(a);
        const int dist_b = distance(b);
        if (dist_a == dist_b)
            return less<int>()(a.first, b.first);
        return greater<int>()(dist_a, dist_b);
    }
private:
    int distance(const pair<int, int>& interval) const {
        if (interval.first == -1 || interval.second == num)
            return interval.second - interval.first - 1;
        return (interval.second - interval.first) / 2;
    }

    int num;
};

class ExamRoom {
public:
    ExamRoom(int N)
        : num(N), intervals(Compare(N))
    {
        // add special boundaries
        seats[-1] = {-1, num};
        seats[num] = {-1, num};
        intervals.emplace(-1, num);
    }
    
    int seat() {
        auto max_interval = *(intervals.begin());
        
        // get mid of largest interval
        int mid;
        if (max_interval.first == -1) {
            mid = 0;
        } else if (max_interval.second == num) {
            mid = num - 1;
        } else {
            mid = max_interval.first + (max_interval.second - max_interval.first) / 2;
        }
        
        // maintain neighbors
        seats[mid] = max_interval;
        seats[max_interval.first].second = mid;
        seats[max_interval.second].first = mid;
        
        // maintain intervals
        intervals.erase(max_interval);
        intervals.emplace(max_interval.first, mid);
        intervals.emplace(mid, max_interval.second);
        
        return mid;
    }
    
    void leave(int p) {
        int left = seats[p].first, right = seats[p].second;
        
        // maintain neighbors
        seats.erase(p);
        seats[left].second = right;
        seats[right].first = left;
        
        // maintain intervals
        intervals.erase({left, p});
        intervals.erase({p, right});
        intervals.emplace(left, right);
    }
    
private:
    int num;
    set<pair<int, int>, Compare> intervals; // manage intervals
    unordered_map<int, pair<int, int>> seats; // manage neighbors
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
```

## Max-Heap

```c++
class Compare {
public:
    Compare(int N) : num(N) { }

    bool operator()(pair<int, int>& a, pair<int, int>& b) const {
        int dist_a = distance(a), dist_b = distance(b);
        return dist_a == dist_b ? 
            greater<int>()(a.first, b.first) : less<int>()(dist_a, dist_b);
    }
private:
    int distance(pair<int, int>& interval) const {
        return (interval.first == -1 || interval.second == num) ? 
            interval.second - interval.first - 1 : (interval.second - interval.first) / 2;
    }

    int num;
};

class ExamRoom {
public:
    ExamRoom(int N)
        : num(N), max_heap(Compare(N))
    {
        seats[-1] = {-1, num};
        seats[num] = {-1, num};
        max_heap.emplace(-1, num);
    }
    
    int seat() {
        while (seats.find(max_heap.top().first) == seats.end() ||
               seats.find(max_heap.top().second) == seats.end() ||
               seats[max_heap.top().first].second != max_heap.top().second ||
               seats[max_heap.top().second].first != max_heap.top().first) {
            max_heap.pop();  // lazy deletion
        }
        
        auto max_interval = max_heap.top(); max_heap.pop();
        
        int mid;
        if (max_interval.first == -1) {
            mid = 0;
        } else if (max_interval.second == num) {
            mid = num - 1;
        } else {
            mid = max_interval.first + (max_interval.second - max_interval.first) / 2;
        }

        seats[mid] = max_interval;
        seats[max_interval.first].second = mid;
        seats[max_interval.second].first = mid;
        max_heap.emplace(max_interval.first, mid);
        max_heap.emplace(mid, max_interval.second);
        
        return mid;
    }
    
    void leave(int p) {
        int left = seats[p].first, right = seats[p].second;
        seats.erase(p);
        seats[left].second = right;
        seats[right].first = left;
        max_heap.emplace(left, right);
    }
    
private:
    int num;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> max_heap;
    unordered_map<int, pair<int, int>> seats;
};
```
