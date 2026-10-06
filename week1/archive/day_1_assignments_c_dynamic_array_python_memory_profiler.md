# Day 1 Assignments: C++ Dynamic Array & Python Memory Profiler

## Assignment 1 (C++): Implement Custom Dynamic Array `MyVector`

### Objective
Write a template dynamic array class `MyVector<T>` in C++ from scratch using raw pointers and dynamic memory management without using `std::vector`.

### Requirements
1. **Internal State:**
   * `T* data`: Raw pointer to dynamically allocated array on the heap.
   * `size_t capacity_`: Maximum allocated elements before re-allocation.
   * `size_t size_`: Current number of elements stored.

2. **Core Operations:**
   * **Constructor:** `MyVector(size_t initial_capacity = 4)`
   * **Destructor:** `~MyVector()` (Must release all heap memory cleanly).
   * **Push Back:** `void push_back(const T& value)`
     * If `size_ == capacity_`, double capacity ($capacity_{new} = 2 \times capacity_{old}$), allocate new heap block, copy existing elements over, and free old block.
   * **Pop Back:** `void pop_back()` (Removes last element; throws `std::underflow_error` if empty).
   * **Subscript Operator:** `T& operator[](size_t index)` and `const T& operator[](size_t index) const` (With bounds assertion).
   * **Copy Constructor & Copy Assignment:** Implement deep copy logic to satisfy Rule of Three.

3. **Performance Metrics to Verify:**
   * Demonstrate amortized $O(1)$ push back behavior.
   * Verify zero memory leaks using `valgrind` or ASan flags (`g++ -fsanitize=address -g main.cpp`).

---

## Assignment 2 (Python): Memory Profiling & PyObject Overhead

### Objective
Write a Python script that analyzes the memory overhead of various Python data structures compared to raw numeric data.

### Requirements
1. Create a function `profile_memory()` that uses `sys.getsizeof` and `tracemalloc`.
2. Compare the memory consumption of:
   * A Python `list` containing 1,000,000 integers.
   * A Python `tuple` containing 1,000,000 integers.
   * A Python `generator` yielding 1,000,000 integers.
3. Log the baseline vs peak memory usage using `tracemalloc`.