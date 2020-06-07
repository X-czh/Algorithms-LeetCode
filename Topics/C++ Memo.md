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

## Use User-defined Key-type for Hash-based Containers

(Mostly copied from [Soonts'](https://stackoverflow.com/users/126995/soonts) and [jogojapan's](https://stackoverflow.com/users/777186/jogojapan) [answer](https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key) on Stack Overflow, many thanks to them!)

To be able to use std::unordered_map (or one of the other unordered associative containers) with a user-defined key-type, you need to define two things:

* A **hash function**: this must be a class that overrides operator() and calculates the hash value given an object of the key-type. One particularly straight-forward way of doing this is to specialize the std::hash template for your key-type.

* A **comparison function for equality**: this is required because the hash cannot rely on the fact that the hash function will always provide a unique hash value for every distinct key (i.e., it needs to be able to deal with collisions), so it needs a way to compare two given keys for an exact match. You can implement this either as a class that overrides operator(), or as a specialization of std::equal, or – easiest of all – by overloading operator==() for your key type (as you did already).

The difficulty with the hash function is that if your key type consists of several members, you will usually have the hash function calculate hash values for the individual members, and then somehow combine them into one hash value for the entire object. A fairly good starting point for a hash function is one that uses bit shifting and bitwise XOR to combine the individual hash values.

To define a hash function for our user-defined key-type T:

* Either define our own hash function for type T:

```c++
struct my_hash {
    template <class T>
    std::size_t operator()(const T& v) const
    {
        // ... hash function here ...
    }
};

std::unordered_set<T, my_hash> s;
std::unordered_map<T, int, my_hash> m;
```

* Or add a specialization of std::hash for type T:

```c++
namespace std {
    template<>
    struct hash<T> {
        size_t operator()(const T& v) const
        {
            // ... hash function here ...
        }
    };
}

std::unordered_set<T> s;
std::unordered_map<T, int> m;
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
