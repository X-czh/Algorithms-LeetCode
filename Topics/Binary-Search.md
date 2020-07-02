# Binary Search

## Introduction

(Copied from a fantastic [article](https://www.topcoder.com/community/competitive-programming/tutorials/binary-search) written by Iovro on Topcoder, which dives deeper in theory.)

> In its simplest form, binary search is used to quickly find a value in a sorted sequence (consider a sequence an ordinary array for now). Binary search maintains a contiguous subsequence of the starting sequence where the target value is surely located. This is called the search space. The search space is initially the entire sequence. At each step, the algorithm compares the median value in the search space to the target value. Based on the comparison and because the sequence is sorted, it can then eliminate half of the search space. By doing this repeatedly, it will eventually be left with a search space consisting of a single element, the target value.

From a more general scope, binary search is a special kind of divide-and-conquer techniques, and Binary Search Trees (BSTs) as well as B+ trees are all based on it.

## Five Basic Variants

(Adapted from [a GeeksforGeeks article](https://www.geeksforgeeks.org/variants-of-binary-search/).)

Assume the array is sorted in ascending order and hi >= lo initially.

### 1. Contains key (True or False)

Returns:

* True if key belongs to array.
* False if key doesn't belong to array.

Corresponds to `std::binary_search` in C++.

```c++
bool contains(vector<int>& a, int lo, int hi, int key)
{
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2; // NOTE: avoids possible overflow caused by (lo + hi)!
        if (a[mid] == key) {
            return true;
        } else if (a[mid] < key) {
            // search HIGH part
            lo = mid + 1;
        } else {
            // search LOW part
            hi = mid - 1;
        }
    }
    return false;
}
```

### 2. Index of first occurrence of a key

Returns:

* First occurrence index of key in range [lo, hi] if key belongs to array
* -1 if key doesn't belong to array

Corresponds to `std::lower_bound` in C++.

(Not care which occurrence? Just return when `a[mid] == key`!)

```c++
int first(vector<int>& a, int lo, int hi, int key)
{
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) {
            // found, note down curr index
            ans = mid;
            // continue searching LOW part
            hi = mid - 1;
        } else if (a[mid] < key) {
            // search HIGH part
            lo = mid + 1;
        } else {
            // search LOW part
            hi = mid - 1;
        }
    }
    return ans;
}
```

### 3. Index of last occurrence of a key

Returns:

* Last occurrence index of key in range [lo, hi] if key belongs to array
* -1 if key doesn't belong to array

```c++
int last(vector<int>& a, int lo, int hi, int key)
{
    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) {
            // found, note down curr index
            ans = mid;
            // continue searching HIGH part
            lo = mid + 1;
        } else if (a[mid] < key) {
            // search HIGH part
            lo = mid + 1;
        } else {
            // search LOW part
            hi = mid - 1;
        }
    }
    return ans;
}
```

### 4. Index of (first) smallest element greater than key / Insertion point of key (the last among duplicates  after insertion)

Returns:

* Index of (first) smallest element greater than key in range [lo, hi] if key is not >= the whole array
* -1 if key >= the whole array

For insertion point of key (the last among duplicates after insertion):

* Initialize `ans = hi + 1`.

Corresponds to `std::upper_bound` in C++.

```c++
int min_greater(vector<int>& a, int lo, int hi, int key)
{
    int ans = -1;
    while (low <= high) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) {
            // search HIGH part
            lo = mid + 1;
        } else if (a[mid] < key) {
            // search HIGH part
            lo = mid + 1;
        } else {
            // found a greater element, note down curr index
            ans = mid;
            // continue search LOW part
            hi = mid - 1;
        }
    }
    return ans;
}
```

### 5. Index of (last) greatest element less than key / Insertion point of key (the first among duplicates  after insertion)

Returns:

* Index of (last) greatest element less than key in range [lo, hi] if key is not <= the whole array
* -1 if key <= the whole array

For insertion point of key (the first among duplicates after insertion):

* Initialize `ans = lo - 1`.
* Return `ans + 1` (as we want to insert key at the index right after the last greatest element less than key.

```c++
int max_lesser(vector<int>& a, int lo, int hi, int key)
{
    int ans = -1;
    while (low <= high) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) {
            // search LOW part
            hi = mid - 1;
        } else if (a[mid] < key) {
            // found a lesser element, note down curr index
            ans = mid;
            // continue search HIGH part
            lo = mid + 1;
        } else {
            // search LOW part
            hi = mid - 1;
        }
    }
    return ans;
}
```

### Related Problems

* (Variant 1) [704-Binary Search](../700-799/704-Binary-Search.cpp)
* (Variant 2 & 3) [034-Find First and Last Position of Element in Sorted Array](../000-099/034-Find-First-and-Last-Position-of-Element-in-Sorted-Array.cpp)
* (Variant 4) [744-Find Smallest Letter Greater Than Target](../700-799/744-Find-Smallest-Letter-Greater-Than-Target.cpp)
* (Variant 4 & 5) [035-Search Insert Position](../000-099/035-Search-Insert-Position.cpp)

## More Variants

### Search in Rotated Sorted Array

* [033-Search in Rotated Sorted Array](../000-099/033-Search-in-Rotated-Sorted-Array.md)
* With duplicates: [081-Search in Rotated Sorted Array II](./000-099/081-Search-in-Rotated-Sorted-Array-II.md)

### Search in 2D Matrix

* [074-Search a 2D Matrix](../000-099/074-Search-a-2D-Matrix.cpp)

### Find Turning Point of Monotonicity in Array

* [153-Find Minimum in Rotated Sorted Array](../100-199/153-Find-Minimum-in-Rotated-Sorted-Array.cpp)
* With duplicates: [154-Find Minimum in Rotated Sorted Array II](../100-199/154-Find-Minimum-in-Rotated-Sorted-Array-II.cpp)
* [162-Find Peak Element](../100-199/162-Find-Peak-Element.cpp)
* Find Peak + 2 Binary Searches: [1095-Find in Mountain Array](../1000-1099/1095-Find-in-Mountain-Array.cpp)

### Exponential Search (esp. for unbounded lists)

Exponential search allows for searching through a sorted, unbounded list for a target value. The algorithm first finds a range in which the target would reside if it were in the list by searching for the first exponent i where the value a^i (typ. a = 2) is greater than the target value. It then performs a binary search on this range. The algorithm is also appliable on bounded lists, and may even out-perform direct binary search when the target value is near the beginning of the list.

* [702-Search in a Sorted Array of Unknown Size](../700-799/702-Search-in-a-Sorted-Array-of-Unknown-Size.cpp)

### Other Wild Variants (I don't know how to summarize :)

* [300-Longest Increasing Subsequence](300-Longest-Increasing-Subsequence.md)
