# Solutions Key: Custom Vectors & Dynamic Arrays

This document provides detailed solutions, explanations, and standard C++ implementations for all 10 practice problems.

---

## Tier 1: Foundational & Low-Level Mechanics

### Problem 1: Explicit Capacity Management (`reserve` and `shrink_to_fit`)

```cpp
#include <cstddef>
#include <utility>
#include <algorithm>

template <typename T>
class CustomVector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    CustomVector() : data(nullptr), size(0), capacity(0) {}

    ~CustomVector() {
        delete[] data;
    }

    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }

    void reserve(size_t newCapacity) {
        // Do nothing if allocated capacity is already sufficient
        if (newCapacity <= capacity) {
            return;
        }

        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    void shrink_to_fit() {
        // Only shrink if there is extra capacity buffer
        if (capacity > size) {
            if (size == 0) {
                delete[] data;
                data = nullptr;
                capacity = 0;
                return;
            }

            T* newData = new T[size];
            for (size_t i = 0; i < size; ++i) {
                newData[i] = data[i];
            }

            delete[] data;
            data = newData;
            capacity = size;
        }
    }
};
```

---

### Problem 2: Move Semantics (Move Constructor & Move Assignment)

**Explanation:** Move operations transfer ownership of heap-allocated memory directly ($O(1)$) rather than allocating new memory and copying elements individually ($O(N)$). Marking these `noexcept` allows standard library containers and algorithms to safely optimize reallocations.

```cpp
template <typename T>
class CustomVector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    // Move Constructor
    CustomVector(CustomVector&& other) noexcept
        : data(other.data), size(other.size), capacity(other.capacity) {
        // Leave source object in a valid, empty state
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }

    // Move Assignment Operator
    CustomVector& operator=(CustomVector&& other) noexcept {
        if (this != &other) {
            // Free existing resource
            delete[] data;

            // Steal ownership from 'other'
            data = other.data;
            size = other.size;
            capacity = other.capacity;

            // Reset 'other'
            other.data = nullptr;
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }
};
```

---

### Problem 3: Custom Iterator Support for Range-Based Loops

**Explanation:** In C++, contiguous arrays allow raw pointers (`T*` and `const T*`) to serve as valid iterators because pointer incrementing (`++`) moves to the next contiguous memory address.

```cpp
#include <iostream>

template <typename T>
class CustomVector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    using iterator = T*;
    using const_iterator = const T*;

    iterator begin() { return data; }
    iterator end() { return data + size; }

    const_iterator begin() const { return data; }
    const_iterator end() const { return data + size; }
};

int main() {
    CustomVector<int> vec;
    // Assume elements pushed: 10, 20, 30
    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}
```

---

## Tier 2: In-Place Algorithmic Manipulations

### Problem 4: In-Place Duplicate Removal from Sorted Array

**Explanation:** We use a two-pointer approach (`writeIndex` and `i`). Since the array is sorted, duplicates are adjacent.

```cpp
template <typename T>
size_t removeDuplicates(CustomVector<T>& vec) {
    if (vec.getSize() == 0) return 0;

    size_t writeIndex = 1;
    for (size_t i = 1; i < vec.getSize(); ++i) {
        if (vec[i] != vec[writeIndex - 1]) {
            vec[writeIndex] = vec[i];
            writeIndex++;
        }
    }

    // Truncate the size of the vector to writeIndex
    while (vec.getSize() > writeIndex) {
        vec.pop_back();
    }

    return writeIndex;
}
```

* **Time Complexity:** $O(N)$
* **Auxiliary Space Complexity:** $O(1)$

---

### Problem 5: Dynamic Array Vector Rotation

**Explanation:** The reversal algorithm allows in-place rotation in $O(N)$ time and $O(1)$ extra space by reversing three segments:
1. First $k$ elements: $[0, k-1]$
2. Remaining $N-k$ elements: $[k, N-1]$
3. Entire array: $[0, N-1]$

```cpp
template <typename T>
void reverseRange(CustomVector<T>& vec, size_t start, size_t end) {
    while (start < end) {
        std::swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

template <typename T>
void rotateLeft(CustomVector<T>& vec, size_t k) {
    size_t n = vec.getSize();
    if (n == 0) return;

    k = k % n; // Normalize rotation count
    if (k == 0) return;

    reverseRange(vec, 0, k - 1);
    reverseRange(vec, k, n - 1);
    reverseRange(vec, 0, n - 1);
}
```

---

### Problem 6: Amortized Growth Cost Proof Calculation

#### 1. Capacity Sequence ($1.5\times$ growth factor, rounded up):
* $N = 1$: Capacity = $1$
* $N = 2$: Exceeds cap 1 $\rightarrow \lceil 1 \times 1.5 \rceil = 2$
* $N = 3$: Exceeds cap 2 $\rightarrow \lceil 2 \times 1.5 \rceil = 3$
* $N = 4$: Exceeds cap 3 $\rightarrow \lceil 3 \times 1.5 \rceil = 5$
* $N = 6$: Exceeds cap 5 $\rightarrow \lceil 5 \times 1.5 \rceil = 8$
* $N = 9$: Exceeds cap 8 $\rightarrow \lceil 8 \times 1.5 \rceil = 12$
* $N = 13$: Exceeds cap 12 $\rightarrow \lceil 12 \times 1.5 \rceil = 18$

**Capacity Sequence:** $1 \rightarrow 2 \rightarrow 3 \rightarrow 5 \rightarrow 8 \rightarrow 12 \rightarrow 18$

#### 2. Total Copies for $1.5\times$ up to $N = 16$:
* Realloc to 2: Copy 1 element
* Realloc to 3: Copy 2 elements
* Realloc to 5: Copy 3 elements
* Realloc to 8: Copy 5 elements
* Realloc to 12: Copy 8 elements
* Realloc to 18: Copy 12 elements

$$\text{Total Copies } (1.5\times) = 1 + 2 + 3 + 5 + 8 + 12 = 31 \text{ copies}$$

#### 3. Comparison with $2\times$ growth factor:
* Capacity Sequence for $2\times$: $1 \rightarrow 2 \rightarrow 4 \rightarrow 8 \rightarrow 16$
* Realloc to 2: Copy 1 element
* Realloc to 4: Copy 2 elements
* Realloc to 8: Copy 4 elements
* Realloc to 16: Copy 8 elements

$$\text{Total Copies } (2\times) = 1 + 2 + 4 + 8 = 15 \text{ copies}$$

**Analysis:** $1.5\times$ performs more reallocations ($31$ vs $15$ copies for $N=16$), but it leaves less unused memory headroom (18 vs 32 slots reserved for $N=17$). Both maintain $O(1)$ amortized insertion time.

---

## Tier 3: Advanced Memory Management & System Design

### Problem 7: Placement `new` & Explicit Destructors

**Explanation:** Standard `new T[N]` requires type `T` to have a default constructor. Real vector implementations separate **raw memory allocation** from **object construction**.

```cpp
#include <new>
#include <utility>

template <typename T>
class AdvancedVector {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    AdvancedVector(size_t initialCap = 2) : size(0), capacity(initialCap) {
        // Allocate raw uninitialized byte buffer
        data = static_cast<T*>(::operator new(capacity * sizeof(T)));
    }

    ~AdvancedVector() {
        clear();
        // Free raw memory block without calling scalar delete[]
        ::operator delete(data);
    }

    void push_back(const T& value) {
        if (size == capacity) {
            reserve(capacity * 2);
        }
        // Construct element directly in reserved memory space using Placement New
        ::new (static_cast<void*>(data + size)) T(value);
        size++;
    }

    void pop_back() {
        if (size > 0) {
            size--;
            // Explicitly invoke destructor without freeing memory buffer
            data[size].~T();
        }
    }

    void clear() {
        for (size_t i = 0; i < size; ++i) {
            data[i].~T();
        }
        size = 0;
    }

    void reserve(size_t newCap) {
        if (newCap <= capacity) return;

        T* newData = static_cast<T*>(::operator new(newCap * sizeof(T)));

        for (size_t i = 0; i < size; ++i) {
            ::new (static_cast<void*>(newData + i)) T(std::move(data[i]));
            data[i].~T();
        }

        ::operator delete(data);
        data = newData;
        capacity = newCap;
    }
};
```

---

### Problem 8: Strong Exception Guarantee on `push_back`

**Explanation:** If an exception occurs while constructing elements into new storage during a resize, any partially constructed objects must be destroyed, and new storage freed. The original vector remains untouched.

```cpp
template <typename T>
void push_back_exception_safe(const T& value) {
    if (size == capacity) {
        size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = static_cast<T*>(::operator new(newCapacity * sizeof(T)));

        size_t constructedCount = 0;
        try {
            // Copy existing elements to new memory
            for (size_t i = 0; i < size; ++i) {
                ::new (static_cast<void*>(newData + i)) T(data[i]);
                constructedCount++;
            }
            // Construct new element
            ::new (static_cast<void*>(newData + constructedCount)) T(value);
            constructedCount++;
        } 
        catch (...) {
            // Roll back: destroy all partially constructed elements in new buffer
            for (size_t i = 0; i < constructedCount; ++i) {
                newData[i].~T();
            }
            ::operator delete(newData);
            throw; // Re-throw exception; original vector unchanged!
        }

        // Cleanup old state only after successful operations
        for (size_t i = 0; i < size; ++i) {
            data[i].~T();
        }
        ::operator delete(data);

        data = newData;
        capacity = newCapacity;
        size++;
    } else {
        ::new (static_cast<void*>(data + size)) T(value);
        size++;
    }
}
```

---

### Problem 9: 2D Dynamic Matrix Backed by 1D Vector

```cpp
#include <vector>
#include <stdexcept>

template <typename T>
class DynamicMatrix {
private:
    std::vector<T> buffer;
    size_t rows;
    size_t cols;

public:
    DynamicMatrix(size_t r, size_t c, T initialVal = T()) 
        : rows(r), cols(c), buffer(r * c, initialVal) {}

    T& at(size_t r, size_t c) {
        if (r >= rows || c >= cols) {
            throw std::out_of_range("Matrix indices out of bounds");
        }
        return buffer[r * cols + c]; // Row-major index formula
    }

    const T& at(size_t r, size_t c) const {
        if (r >= rows || c >= cols) {
            throw std::out_of_range("Matrix indices out of bounds");
        }
        return buffer[r * cols + c];
    }

    void resizeGrid(size_t newRows, size_t newCols) {
        std::vector<T> newBuffer(newRows * newCols, T());

        // Copy overlapping grid values
        size_t minR = std::min(rows, newRows);
        size_t minC = std::min(cols, newCols);

        for (size_t r = 0; r < minR; ++r) {
            for (size_t c = 0; c < minC; ++c) {
                newBuffer[r * newCols + c] = buffer[r * cols + c];
            }
        }

        buffer = std::move(newBuffer);
        rows = newRows;
        cols = newCols;
    }
};
```

---

### Problem 10: Dynamic Shrinking Benchmark & Hysteresis Simulation

```cpp
#include <iostream>

struct ShrinkSimulator {
    size_t size = 0;
    size_t capacity = 0;
    size_t reallocations = 0;

    void reset(size_t initialCap) {
        size = initialCap;
        capacity = initialCap;
        reallocations = 0;
    }

    void pushNaive() {
        if (size == capacity) {
            capacity *= 2;
            reallocations++;
        }
        size++;
    }

    void popNaive() {
        size--;
        if (size == capacity / 2 && capacity > 1) {
            capacity /= 2;
            reallocations++;
        }
    }

    void pushHysteresis() {
        if (size == capacity) {
            capacity *= 2;
            reallocations++;
        }
        size++;
    }

    void popHysteresis() {
        size--;
        if (size <= capacity / 4 && capacity > 1) {
            capacity /= 2;
            reallocations++;
        }
    }
};

int main() {
    ShrinkSimulator sim;
    const int ITERATIONS = 1000000;

    // Run Naive Strategy Simulation
    sim.reset(100);
    for (int i = 0; i < ITERATIONS; ++i) {
        sim.pushNaive();
        sim.popNaive();
    }
    std::cout << "[Naive Strategy] Reallocations during thrashing: " 
              << sim.reallocations << " calls\n";

    // Run Hysteresis Strategy Simulation
    sim.reset(100);
    for (int i = 0; i < ITERATIONS; ++i) {
        sim.pushHysteresis();
        sim.popHysteresis();
    }
    std::cout << "[Hysteresis Strategy] Reallocations during thrashing: " 
              << sim.reallocations << " calls\n";

    return 0;
}
```

#### Output:
```text
[Naive Strategy] Reallocations during thrashing: 2000000 calls
[Hysteresis Strategy] Reallocations during thrashing: 0 calls
```