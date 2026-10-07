# Project Specification: Custom Doubly Linked List

## Objective
Implement a fully templated C++ **Doubly Linked List (`CustomLinkedList<T>`)** with sentinel nodes, bidirectional iterators, custom memory destructors, and full support for the C++ Rule of Five.

---

## Technical Requirements

1. **Sentinel Architecture:**
   * Internal `head` and `tail` dummy nodes to eliminate edge cases for empty insertions/deletions.

2. **Template Mechanics:**
   * Support any generic type `T`.

3. **Core API Methods:**
   * `void push_front(const T& value)`
   * `void push_back(const T& value)`
   * `void pop_front()`
   * `void pop_back()`
   * `T& front()` & `const T& front() const`
   * `T& back()` & `const T& back() const`
   * `size_t getSize() const`
   * `bool isEmpty() const`
   * `void clear()`

4. **Iterators:**
   * Nested bidirectional `Iterator` class supporting `operator++`, `operator--`, `operator*`, `operator->`, `operator==`, and `operator!=`.
   * Enable range-based loops: `for (auto& item : list)`.

5. **Rule of Five:**
   * Custom Destructor, Copy Constructor, Copy Assignment, Move Constructor, and Move Assignment.