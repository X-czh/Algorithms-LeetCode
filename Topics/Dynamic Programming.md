# Dynamic Programming

## Introduction

(Adapted from [Wikipedia](https://en.wikipedia.org/wiki/Dynamic_programming#Computer_programming))

Dynamic Programming is nothing more than *smart recursion*, or in other words, *recursion without repetition*. There are two key attributes that a problem must have in order for dynamic programming to be applicable: **optimal substructure** and **overlapping sub-problems**. If a problem can be solved by combining optimal solutions to non-overlapping sub-problems, the strategy is called "divide and conquer" instead.

**Optimal substructure** means that the solution to a given optimization problem can be obtained by the combination of optimal solutions to its sub-problems. Such optimal substructures are usually described by means of recursion.

**Overlapping sub-problems** means that the space of sub-problems must be small, that is, any recursive algorithm solving the problem should solve the same sub-problems over and over, rather than generating new sub-problems. Dynamic programming takes account of this fact and solves each sub-problem only once by storing the solutions of intermediate subproblems.

This can be achieved in either of two ways:

* *Top-down approach*: This is the direct fall-out of the recursive formulation of any problem. If the solution to any problem can be formulated recursively using the solution to its sub-problems, and if its sub-problems are overlapping, then one can easily memoize or store the solutions to the sub-problems in a table. Whenever we attempt to solve a new sub-problem, we first check the table to see if it is already solved. If a solution has been recorded, we can use it directly, otherwise we solve the sub-problem and add its solution to the table.

* *Bottom-up approach*: Once we formulate the solution to a problem recursively as in terms of its sub-problems, we can try reformulating the problem in a bottom-up fashion: try solving the sub-problems first and use their solutions to build-on and arrive at solutions to bigger sub-problems. This is also usually done in a tabular form by iteratively generating solutions to bigger and bigger sub-problems by using the solutions to small sub-problems. Note that the order of iteration of the the sub-problems is important.

## Example: Fibonacci number

### Naive recursive implementation: O(2^n) time, O(2^n) space

The first step to apply dynamic programming to identify the recurrence structure of the problem and write down the recursive solution. You'll then need to analyze whether there are overlapping sub-problems. Here, we produce a call tree that calls the function on the same value many different times.

```c++
int fib(int n) {
    if n <= 1 return n;
    return fib(n - 1) + fib(n - 2);
}
```

### Top-down approach (memoization): O(n) time, O(n) space

We use a map to retain all intermediate results through the entire computation, and proceed in a top-down way.

Aside: Why memoization instead of memo**R**ization? See [here](https://stackoverflow.com/questions/45242851/why-memoization-instead-of-memorization).

```c++
int helper(int n, unordered_map<int, int>& mem) {
    if n <= 1 return n;
    if (mem.find(n) != m.end()) return mem[n];
    return helper(n - 1) + helper(n - 2);
}

int fib(int n) {
    unordered_map<int, int> mem;
    return helper(n, mem);
}
```

### Bottom-up approach: O(n) time, O(n) space

We use an array to retain all intermediate results through the entire computation, and proceed in a bottom-up way.

```c++
int fib(int n) {
    if (n == 0) {
        return 0;
    }

    vector<int> mem(n);
    mem[0] = 0;
    mem[1] = 1;
    for (int i = 2; i < n; i++) {
        mem[i] = mem[i - 1] + mem[i - 2];
    }
    return mem[n];
}
```

### Bottom-up approach, space optimized: O(n) time, O(1) space

In many dynamic programming algorithms, it is not necessary to retain all intermediate results through the entire computation. Here, we can significantly reduce the space  requirements of our algorithm by maintaining only the two newest elements of the array. More generally, if the solution to a problem of size n can be formulated recursively as in terms of its f(n) sub-problems, then O(f(n)) auxiliary space is needed. When f(n) is a constant, as is the case here, O(1) auxiliary space is needed.

```c++
int fib(int n) {
    if (n == 0) {
        return 0;
    }

    int prev = 0;
    int curr = 1;
    for (int i = 1; i < n; i++) {
        int temp = prev + curr;
        prev = curr;
        curr = temp;
    }
    return curr;
}
```

## Dynamic Programming on Trees

## Dynamic Programming in DAGs
