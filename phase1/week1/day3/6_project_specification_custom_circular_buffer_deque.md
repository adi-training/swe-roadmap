# Project Specification: Custom Circular Buffer Deque (`CustomDeque<T>`)

## Objective
Implement a high-performance, contiguous template **Circular Double-Ended Queue (`CustomDeque<T>`)** in C++. The container must support $O(1)$ insertions and deletions at both ends (`push_front`, `push_back`, `pop_front`, `pop_back`), automatic dynamic resizing with circular index re-alignment, and the full C++ Rule of Five.

---

## Technical Requirements

1. **Circular Ring Storage:**
   * Dynamic internal array `T* buffer`.
   * Pointers/Indices: `head`, `tail`, `size`, and `capacity`.
   * Wrapping arithmetic via modulo operations (`(index + 1) % capacity`).

2. **Core API Methods:**
   * `void push_back(const T& value)`
   * `void push_front(const T& value)`
   * `void pop_back()`
   * `void pop_front()`
   * `T& front()` & `const T& front() const`
   * `T& back()` & `const T& back() const`
   * `T& operator[](size_t index)` (Logical 0-indexed lookup relative to `head`)
   * `size_t getSize() const`
   * `bool isEmpty() const`
   * `void clear()`

3. **Dynamic Buffer Resizing:**
   * Automatically double buffer capacity when `size == capacity`.
   * Re-align elements sequentially starting from logical index $0$ to `size - 1` upon expansion.

4. **Rule of Five & Memory Safety:**
   * Destructor, Copy Constructor, Copy Assignment, Move Constructor, and Move Assignment.