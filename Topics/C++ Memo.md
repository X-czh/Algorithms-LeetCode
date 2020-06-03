# C++ Memo

## String

### Tokenize String

```c++
vector<string> toTokenVector(string str)
{
    vector<string> out;
    istringstream tokenStream(str);
    string token;
    char delim = ',';
    while (getline(tokenStream, token, delim)) {
        out.push_back(token);
    }
    return out;
}
```

## Vector

### Swap the contents of two vectors (in constant time!)

```c++
v1.swap(v2);
```

Exchanges the contents of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.

## Queue

### Custom comparator for priority queue

Note that the Compare parameter is defined such that it returns true if its first argument comes before its second argument in a weak ordering. But because the priority queue outputs largest elements first, the elements that "come before" are actually output last. That is, the front of the queue contains the "last" element according to the weak ordering imposed by Compare.

```c++
auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);
```

## List

### Delete a list node when traversing the list (Ugly though)

```c++
for (auto i = list.begin(), e = list.end(); i != e;) {
    if (shouldDelete(*i)) {
        i = list.erase(i);
    } else {
        ++i;
    }
}
```

## Lambda Expression

### Lambda capture

```c++
struct S2 { void f(int i); };
void S2::f(int i)
{
    [&] {};             // OK: by-reference capture default
    [&, i] {};          // OK: by-reference capture, except i is captured by copy
    [&, &i] {};         // Error: by-reference capture when by-reference is the default
    [&, this] {};       // OK, equivalent to [&]
    [&, this, i] {};    // OK, equivalent to [&, i]

    [=] {};             // OK: by-copy capture default
    [=, &i] {};         // OK: by-copy capture, except i is captured by reference
    [=, *this] {};      // until C++17: Error: invalid syntax
                        // since c++17: OK: captures the enclosing S2 by copy
    [=, this] {};       // until C++20: Error: this when = is the default
                        // since C++20: OK, same as [=]
}
```
