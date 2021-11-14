# Online Judge

## C++ Techniques

### Fast I/O
1. Disable the synchronization between the C and C++ standard streams
```c++
std::ios_base::sync_with_stdio(false);
```
2. Untie `cin` from `cout`
```
std::cin.tie(nullptr);
```

### Standard Library
* [Iterators](https://en.cppreference.com/w/cpp/header/iterator)
* [Containers](https://en.cppreference.com/w/cpp/container)
* [Algorithms](https://en.cppreference.com/w/cpp/algorithm)

***

### Containers
#### Sequence Containers
##### [Vectors](https://en.cppreference.com/w/cpp/container/vector)
1. Constructors
    * Empty vector: `vector<T> v;` / `vector<T>{};`
    * `vector<T> v(n);`
    * `vector<T> v(n, val);`
    * [List initialization](https://en.cppreference.com/w/cpp/language/list_initialization): `vector<T> v = {t1, t2, t3};` 
2. Member Functions
    * `push_back(elem)`
    * `pop_back()`
    * `resize(n, elem)`: Resizes the container so that it contains n elements.
        - If `n` is greater than the current container size and `elem` is specified, then the new elements are initialized as copies of `elem`.
    * `assign(n, elem)`: Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.

##### [Arrays](https://en.cppreference.com/w/cpp/container/array)
1. Constructors
    * Empty array: `array<T, N> a;` / `array<T, N> a{};`
2. Member Functions
    * `fill(elem)`: Assigns the given `elem` value to all elements in the container.

### Algorithms
1. [nth_element](https://en.cppreference.com/w/cpp/algorithm/nth_element)
    * `nth_element(first, nth, last);`
