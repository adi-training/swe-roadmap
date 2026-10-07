# Tricky Interview & Coding Questions: Stacks & Queues

## Part 1: Conceptual & System Design Questions

### Q1: Why is `std::stack` defined as a Container Adaptor in C++ STL rather than an independent class?

**Answer:**
`std::stack` does not manage underlying dynamic memory directly. Instead, it provides a restricted LIFO interface (`push`, `pop`, `top`) wrapping an existing sequential container (`std::deque` by default, or optionally `std::vector` or `std::list`).

```cpp
// Syntax allows overriding internal container strategy:
std::stack<int, std::vector<int>> customVectorStack;
```

This design separates container interface policies from dynamic memory allocation strategies.

### Q2: Why is `std::deque` preferred over `std::vector` for implementing standard queues or stacks in standard libraries?

**Answer:**
* **`std::vector`:** Popping from the front (`erase(begin())`) forces an $O(N)$ element memory shift.
* **`std::deque`:** Manages an array of fixed-size memory chunk pointers. Insertion/deletion at both ends executes in strict $O(1)$ time without shifting remaining elements or invalidating pointers to existing chunks.

---

## Part 2: Advanced Coding Challenges

### Challenge 1: Design a Stack with $O(1)$ `increment` operations (Custom Stack)

**Problem:** Implement a stack supporting `push`, `pop`, and `increment(k, val)` (adds `val` to the bottom $k$ elements) in $O(1)$ amortized time.

**Solution (Lazy Propagation Array):**

```cpp
#include <vector>
#include <algorithm>

class CustomStack {
private:
    std::vector<int> stack;
    std::vector<int> inc; // Lazy increment storage
    int capacity;

public:
    CustomStack(int maxSize) : capacity(maxSize) {}

    void push(int x) {
        if (stack.size() < capacity) {
            stack.push_back(x);
            inc.push_back(0);
        }
    }

    int pop() {
        int idx = stack.size() - 1;
        if (idx < 0) return -1;

        if (idx > 0) {
            inc[idx - 1] += inc[idx]; // Propagate lazy increment down
        }

        int result = stack[idx] + inc[idx];
        stack.pop_back();
        inc.pop_back();
        return result;
    }

    void increment(int k, int val) {
        int idx = std::min(k, (int)stack.size()) - 1;
        if (idx >= 0) {
            inc[idx] += val; // O(1) lazy update at threshold
        }
    }
};
```