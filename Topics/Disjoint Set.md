# Disjoint Set (Union-Find)

A disjoint-set or union-find data structure is a data structure that tracks a set of elements partitioned into a number of disjoint (non-overlapping) subsets. It supports the following operations:

* MAKE-SET(x): creates a new set containing the single element x
* FIND(x): returns the representative of the set containing x
* UNION(x, y): unions the two sets which contains x and y repectively

## Multiway Tree Implementation

```c++
void makeSet(int x)
{
    parent[x] = x;
}

int find(int x)
{
    while (parent[x] != x):
        x = parent[x];
    return x;
}

int union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
    if (xroot != yroot)
        parent[yroot] = xroot;
}
```

## Optimization

### Smart Union

* __*Union by rank*__: attach the shorter tree to the higher tree (we use rank instead of height as path compression will change the tree height dynamicly).

* __*Union by size*__: attach the smaller tree to the larger tree.

To store the rank/size info, we can use either a new array to record that or store the negative rank/size as the parent value of the representative element.

An example of union by rank (use a new array to store rank) is as follows:
```c++
int union(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
    
    // x and y are already in the same set
    if (xroot == yroot)
        return;
    
    // x and y are not in same set, so we merge them
    // merge smaller-rank tree into larger-rank tree
    if (rank[xroot] < rank[yroot])
        swap(xroot, yroot);
    parent[yroot] = xroot;
    if (rank[xroot] == rank[yroot])
        ++rank[xroot];
}
```

### Path Compression

Flatten the tree every time we make a find call for efficient future searches.

```c++
int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
```

## Complexity

Without optimizations, the height of trees can grow unchecked as O(n), implying that Find and Union operations will take O(n) time.

The amortized time complexity is O(alpha(n)) for optimized Union and Find (optimized), where alpha(n) is the inverse Ackermann function. This function has a value alpha(n) < 5 for any value of n that can be written in this physical universe, so the disjoint-set operations take place in essentially constant time.

The space complxity is O(n).

## Application

* Keep track of connected components in a undirected graph
* Find a minimum spanning tree of a graph (Kruskal's algorithm)
