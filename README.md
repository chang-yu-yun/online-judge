# Online Judge

### C++ Techniques
#### Fast I/O
1. Disable the synchronization between the C and C++ standard streams
```c++
std::ios_base::sync_with_stdio(false);
```
2. Untie `cin` from `cout`
```
std::cin.tie(nullptr);
```
#### Standard Library
1. Iterators<br>
    [`<iterator>`](https://en.cppreference.com/w/cpp/header/iterator)
    1. `next(it);`
    2. `prev(it);`
    3. `advance(it, n);`
    4. `distance(it1, it2);`
    5. `iter_swap(it1, it2);`
