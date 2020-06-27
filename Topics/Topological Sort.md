# Topological Sort

## Definition

A topological sort or topological ordering of a directed graph is a linear ordering of its vertices such that for every directed edge u->v, u comes before v in the ordering.

From another view, a topological sort is a linear extension of the partial order represented by the directed graph (this naturally requires that the graph is acyclic), where a linear extensition of a partial order is a total order (or linear order) that is compatible with the partial order.

## Application: Scheduling under Dependency Constraints

If we use nodes to represent tasks, and use directed edges to represent scheduling constraints or dependencies(u->v implies u must be done before v), then a topological sort is a schedule for performing all tasks under the scheduling constraints.

## The Central Theorem (my own words)

A directed graph G is a DAG (Directed Acyclic Graph) <=> it has a topological sort.

## Algorithms

The usual algorithms for topological sorting runs in O(V + E) time and space.

### Kahn’s Algorithm

Choose vertices in the same order as the eventual topological sort.

First, find a list of "start nodes" which have no incoming edges and insert them into a set S; at least one such node must exist in a non-empty acyclic graph. Then, pick one from S, place it in a output list L, update the in-degrees of its successors, and insert those which have no incoming edges into S. Keep doing this until S is empty.

```
L ← Empty list that will contain the sorted nodes
S ← Set of all nodes with in-degree 0

while S not empty do
    remove a node n from S
    append n to L
    for each node v with an edge e from u to v do
        remove edge e from the graph
        if v has in-degree 0 then
            insert v into S

if graph has edges then
    return error  (graph has at least one cycle)
else
    return L  (a topologically sorted order)
```

### Tarjan’s Algorithm (DFS)

Choose vertices in the reverse order as the eventual topological sort.

If during DFS, an active node is visited (a node is active since we first visit it, and it only become finished when all of the nodes reachable from it have been visited), then the graph contains a cycle.

```
L ← Empty list that will contain the sorted nodes

while exists nodes not marked FINISHED do
    select an unmarked node n
    dfs(n)

function dfs(node n)
    if n marked FINISHED then
        return
    if n marked ACTIVE then
        stop  (not a DAG)

    mark n ACTIVE

    for each node v with an edge from u to v do
        dfs(v)

    mark n FINISHED
    add n to head of L
```

## Related Problems

* Existence only: [207-Course Schedule](../200-299/207-Course%20Schedule.md)
* Output ordering: [210-Course Schedule](../200-299/210-Course%20Schedule%20II.md)
* Output ordering: [269-Alien Dictionary](../200-299/269-Alien%20Dictionary.md)
* Level of DAG: [1136-Parallel Courses](../1100-1199/1136-Parallel%20Courses.md)
* Wrong solution with TopSort + Greedy (**A greedy algorithm without proof is simply wrong!**): [1494-Parallel Courses II](../1400-1499/1494-Parallel%20Courses%20II.md)
