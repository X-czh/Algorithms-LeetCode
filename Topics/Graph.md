# Graph

## Representation

Following two are the most commonly used representations of a graph:

1. Adjacency Matrix
2. Adjacency List

### Adjacency Matrix

Adjacency Matrix is a matrix of size V x V where V is the number of vertices in a graph. Let the matrix by adj[][], adj[i][j] = 1 represents that there is an edge from vertex i to vertex j in the graph. An adjacency matrix for undirected graph is always symmetric. For unweighted graph, we can just use adj[i][j] = w to represent that the edge from vertex i to vertex j has weight w.

### Adjacency List

Adjacency List is a size V array of lists where V is the number of vertices. Let the array be adj[], adj[i] represents the list of vertices adjacent to vertex i. This representation can also be used to represent a weighted graph. The weights of edges can be represented as lists of pairs.

## DFS and BFS

DFS: use a stack, often use recursion
BFS: use a queue

## Topological Sort

See [here](Topological-Sort.md).

## Connected Component

547

1. DFS
2. BFS
3. Union Find

## Shortest Path

## Minimum Spanning Tree
