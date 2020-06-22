# Path-Sum

Given a binary tree and a sum, determine the existence/counts of the tree paths whose path sum (adding up all the values along the path) equals the target sum OR find the max/min path sum.

## Root-to-leaf Path Only

Simple DFS.

* (Existence) [112-Path Sum](../100-199/112-Path%20Sum.cpp).
* (Print all paths) [113-Path Sum II](../100-199/113-Path%20Sum%20II.cpp).

## Downwards Path Only

Here, the path does not need to start or end at the root or a leaf, but it must go downwards. The simplest way is to traverse the tree with DFS/BFS, then run the above approach at each node.

Optimizaton: use a hash map to store the prefix sum along the traversal.

* (Counts) [437-Path Sum III](../400-499/437-Path%20Sum%20III.md)
* (Counts; Array Variant) [560-Subarray Sum Equals K](../500-599/560-Subarray%20Sum%20Equals%20K.md)

## Arbitrary Path

Any path in a tree must be either a downwards path or the concatenation of two downwards paths (a central node + two downwards path starting at two different children of the central node, can view the central node + one downwards path as one path).

It is in gerneral difficult to determine the existence/counts of the tree paths whose path sum equals the target sum. However, it is easy to find a recursive solution to the max/min path sum problem.

* (Max path sum) [124-Binary Tree Maximum Path Sum](../100-199/124-Binary%20Tree%20Maximum%20Path%20Sum.md)
