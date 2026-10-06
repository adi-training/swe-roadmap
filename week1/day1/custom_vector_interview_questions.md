# Tricky Interview & Coding Questions: Dynamic Arrays & Custom Vectors

This guide covers real-world technical interview questions ranging from conceptual traps to implementation challenges regarding dynamic arrays, memory management, and dynamic vectors.

---

## Part 1: Conceptual & Analytical Questions

### Q1: Why is array expansion dynamic growth factor multiplicative ($\times 2$ or $\times 1.5$) rather than additive ($+K$)?

**Answer:**
If we grow capacity by a fixed constant $K$ (e.g., adding $100$ slots whenever the array is full):
* Inserting $N$ elements requires resizing roughly $N / K$ times.
* The $i$-th resize copies $i \cdot K$ elements.
* Total copying operations: 
  $$\sum_{i=1}^{N/K} i \cdot K = K \cdot \frac{\frac{N}{K}\left(\frac{N}{K} + 1\right)}{2} = O\left(N^2\right)$$
* Thus, the amortized cost per `push_back` operation becomes **$O(N)$**.

With a multiplicative factor $M > 1$ (e.g., doubling capacity):
* Resizing happens only $\log_M(N)$ times.
* Total copying operations for $N$ elements:
  $$\sum_{i=0}^{\log_2(N)} 2^i = 2^{\log_2(N) + 1} - 1 = 2N - 1 = O(N)$$
* Dividing total cost $O(N)$ by $N$ insertions yields an amortized time complexity of **$O(1)$** per insertion.

---

### Q2: What is the "Thrashing" (or Hysteresis) problem in capacity shrinking?

**Answer:**
A naive shrinking strategy is to halve capacity as soon as `size == capacity / 2`. 

**The Trap:**
Consider a vector currently full at `size == 8` and `capacity == 8`:
1. Push 1 element $\rightarrow$ Resize to `capacity == 16`, `size == 9` ($O(N)$ work).
2. Pop 1 element $\rightarrow$ `size == 8`, shrink to `capacity == 8` ($O(N)$ work).
3. Push 1 element $\rightarrow$ Resize to `capacity == 16` ($O(N)$ work).

Repeatedly pushing and popping at the boundary forces an $O(N)$ reallocation on **every single operation**, ruining amortized efficiency.

**The Solution (Hysteresis):**
Delay shrinking until `size` falls significantly below capacity—typically when `size <= capacity / 4`. When triggered, reduce capacity to `capacity / 2`. This ensures sufficient buffer space before another allocation is required.

---

### Q3: What happens if you do not implement a custom Copy Constructor in C++ for a Vector class containing pointers?

**Answer:**
By default, the compiler provides a **shallow copy** (bitwise copy of member variables):
```cpp
CustomVector v1;
v1.push_back(42);

CustomVector v2 = v1; // Shallow copy
```
* Both `v1.data` and `v2.data` will point to the exact same raw memory address on the heap.
* **Problem 1 (Data Corruption):** Modifying elements in `v2` mutates `v1`.
* **Problem 2 (Double Free Bug):** When `v1` and `v2` go out of scope, both destructors call `delete[] data` on the same memory pointer, causing a memory corruption crash.

**Fix:** Implement a custom Copy Constructor that allocates new heap memory and copies each element individually (**Deep Copy**).

---

### Q4: What is Pointer/Iterator Invalidation?

**Answer:**
Pointer or iterator invalidation occurs when a reference or pointer points to an element inside a vector, but a subsequent vector operation reallocates the underlying array memory.

```cpp
CustomVector<int> vec;
vec.push_back(10);
int* ptr = &vec[0]; // Pointer to first element

// This push causes capacity expansion and memory reallocation!
for (int i = 0; i < 100; ++i) vec.push_back(i);

// CRASH or UNDEFINED BEHAVIOR:
std::cout << *ptr; // ptr points to deallocated heap memory
```

---

## Part 2: Coding Challenges

### Challenge 1: Write an In-Place `erase_if` / Remove-Matching Algorithm

**Problem:** Given a custom vector, remove all elements that satisfy a condition (e.g., all even numbers) in **$O(N)$ time** and **$O(1)$ extra space**.

**Naive Approach (Bad):**
Calling `erase(index)` inside a loop shifts all remaining elements left on every deletion, resulting in $O(N^2)$ runtime complexity.

**Optimal Solution (Two-Pointer / Erase-Remove Idiom):**

```cpp
template <typename T, typename Predicate>
void remove_if_custom(CustomVector<T>& vec, Predicate pred) {
    size_t writeIndex = 0;

    // Shift non-matching elements to the front
    for (size_t readIndex = 0; readIndex < vec.getSize(); ++readIndex) {
        if (!pred(vec[readIndex])) {
            vec[writeIndex] = vec[readIndex];
            writeIndex++;
        }
    }

    // Shrink size to reflect remaining valid elements
    while (vec.getSize() > writeIndex) {
        vec.pop_back();
    }
}
```

---

### Challenge 2: Implement Exception-Safe `resize()`

**Problem:** If memory allocation fails during `resize()`, or if copying an element throws an exception, the vector must remain in a valid, uncorrupted original state (Strong Exception Guarantee).

**Solution:**

```cpp
template <typename T>
void CustomVector<T>::resize(size_t newCapacity) {
    if (newCapacity <= capacity) return;

    // 1. Allocate new block FIRST
    T* newData = new T[newCapacity]; // May throw std::bad_alloc

    // 2. Copy elements to new storage safely
    try {
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i]; // May throw element copy exception
        }
    } catch (...) {
        // Clean up new buffer if copying fails
        delete[] newData;
        throw; // Re-throw exception without corrupting existing 'data'
    }

    // 3. Swap state only AFTER successful copy
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
```

---

### Challenge 3: Deep Copy Constructor & Copy Assignment Operator

**Problem:** Implement a leak-safe Copy Constructor and Copy Assignment Operator (`operator=`) using the Copy-and-Swap idiom.

**Solution:**

```cpp
template <typename T>
class CustomVector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    // ... basic constructors ...

    // 1. Deep Copy Constructor
    CustomVector(const CustomVector& other) 
        : size(other.size), capacity(other.capacity), data(new T[other.capacity]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    // Friend swap helper
    friend void swap(CustomVector& first, CustomVector& second) noexcept {
        using std::swap;
        swap(first.data, second.data);
        swap(first.size, second.size);
        swap(first.capacity, second.capacity);
    }

    // 2. Copy Assignment Operator using Copy-and-Swap Idiom
    CustomVector& operator=(CustomVector other) { // Passed by value (invokes copy constructor)
        swap(*this, other); // Swap internal pointers with temp copy
        return *this;
    } // 'other' goes out of scope and frees the old buffer automatically
};
```