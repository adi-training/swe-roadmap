# Build and Test a Custom Vector

Welcome! A **Custom Vector** (or dynamic array) is one of the most fundamental data structures in computer science. If you have ever wondered how arrays in C++ (`std::vector`), Python lists, or Java `ArrayList` grow automatically when you add elements, this guide is for you.

---

## 1. Conceptual Mental Model

Imagine a normal array like a row of fixed wooden lockers. If you buy 5 lockers, you can only store 5 items. If you buy a 6th item, you are out of room.

A **Vector** solves this by acting like an elastic row of lockers:
1. It starts with a default **Capacity** (e.g., 2 slots).
2. As you add items, **Size** tracks how many slots are filled.
3. When **Size** reaches **Capacity** and you try to add another item:
   - It allocates a brand-new, bigger row of lockers (usually double the size: $2 \times \text{capacity}$).
   - It copies all existing items into the new lockers.
   - It destroys the old lockers.
   - It places the new item in the next available slot.

### Key Terminology
* **Size ($n$):** The number of elements currently stored in the vector.
* **Capacity ($c$):** The total number of memory slots currently allocated.
* **Growth Factor:** The multiplier used when resizing (commonly $2$).
* **Amortized Time Complexity:** Pushing an item is usually $O(1)$, but occasionally $O(n)$ when a dynamic allocation and copy occurs.

---

## 2. Structural Breakdown of a Custom Vector

To implement a vector (e.g., in C++), your class needs three core member variables:

```cpp
template <typename T>
class CustomVector {
private:
    T* data;           // Pointer to contiguous memory array
    size_t size;       // Number of active elements
    size_t capacity;   // Total memory slots allocated

    void resize(size_t newCapacity); // Internal helper function
public:
    // ... public methods
};
```

---

## 3. End-to-End Implementation Roadmap

Follow these implementation steps in order:

### Step 1: Constructors & Destructor
* **Default Constructor:** Initialize `size = 0`, `capacity = 2` (or initial capacity), and allocate dynamic array `data = new T[capacity]`.
* **Destructor:** Free allocated memory using `delete[] data` to prevent memory leaks.

### Step 2: Capacity Management (`resize`)
* Allocate new memory buffer of size `newCapacity`.
* Copy existing elements from `data` to new buffer.
* Deallocate old buffer `delete[] data`.
* Point `data` to the new buffer and update `capacity = newCapacity`.

### Step 3: Pushing Elements (`push_back`)
* Check if `size == capacity`. If yes, call `resize(capacity * 2)`.
* Insert item at `data[size]`.
* Increment `size` by $1$.

### Step 4: Removing Elements (`pop_back`)
* Check if vector is empty (`size == 0`). If so, throw an error or warning.
* Decrement `size` by $1$.
* Optional: Shrink capacity if `size <= capacity / 4` to optimize memory usage.

### Step 5: Accessors (`operator[]`, `at`, `getSize`, `getCapacity`)
* `operator[](size_t index)`: Return `data[index]` for direct, fast access.
* `at(size_t index)`: Return `data[index]` with safety bounds checking ($0 \le \text{index} < \text{size}$).

---

## 4. Sequential Testing Guide

When building a data structure, test incrementally! Do not write all the code at once. Follow this step-by-step verification process.

```
       +------------------------------------+
       |  Test 1: Initialization & Empty    |
       +-----------------+------------------+
                         |
                         v
       +-----------------+------------------+
       |  Test 2: Sequential Insertion      |
       +-----------------+------------------+
                         |
                         v
       +-----------------+------------------+
       |  Test 3: Automatic Resizing        |
       +-----------------+------------------+
                         |
                         v
       +-----------------+------------------+
       |  Test 4: Element Access & Bounds   |
       +-----------------+------------------+
                         |
                         v
       +-----------------+------------------+
       |  Test 5: Deletion & Shrinking      |
       +-----------------+------------------+
                         |
                         v
       +-----------------+------------------+
       |  Test 6: Memory Cleanup Check      |
       +------------------------------------+
```

---

## 5. Detailed Test Suite Code (C++)

Here is a simple, copy-pasteable test harness you can run to verify your `CustomVector` implementation step by step.

```cpp
#include <iostream>
#include <cassert>
#include <stdexcept>

// Include or define your CustomVector header here
// #include "CustomVector.hpp"

void runAllTests() {
    std::cout << "==========================================\n";
    std::cout << "    STARTING CUSTOM VECTOR TEST SUITE    \n";
    std::cout << "==========================================\n\n";

    // ----------------------------------------------------
    // TEST 1: Construction & Empty State
    // ----------------------------------------------------
    std::cout << "[Test 1] Testing Default Initialization... ";
    {
        CustomVector<int> vec;
        assert(vec.getSize() == 0);
        assert(vec.getCapacity() >= 0);
        assert(vec.isEmpty() == true);
    }
    std::cout << "PASSED!\n";

    // ----------------------------------------------------
    // TEST 2: Single and Multiple Push Backs
    // ----------------------------------------------------
    std::cout << "[Test 2] Testing Single & Multiple Push Back... ";
    {
        CustomVector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);

        assert(vec.getSize() == 3);
        assert(vec[0] == 10);
        assert(vec[1] == 20);
        assert(vec[2] == 30);
    }
    std::cout << "PASSED!\n";

    // ----------------------------------------------------
    // TEST 3: Dynamic Resizing (Capacity Expansion)
    // ----------------------------------------------------
    std::cout << "[Test 3] Testing Dynamic Capacity Expansion... ";
    {
        CustomVector<int> vec;
        size_t initialCapacity = vec.getCapacity();
        
        // Push enough items to guarantee a resize
        for (int i = 0; i < 50; ++i) {
            vec.push_back(i);
        }

        assert(vec.getSize() == 50);
        assert(vec.getCapacity() > initialCapacity);
        
        // Verify value integrity after memory reallocation
        for (int i = 0; i < 50; ++i) {
            assert(vec[i] == i);
        }
    }
    std::cout << "PASSED!\n";

    // ----------------------------------------------------
    // TEST 4: Element Access & Safety Bounds
    // ----------------------------------------------------
    std::cout << "[Test 4] Testing Access Methods and Exceptions... ";
    {
        CustomVector<std::string> vec;
        vec.push_back("Apple");
        vec.push_back("Banana");

        assert(vec.at(0) == "Apple");
        assert(vec.at(1) == "Banana");

        // Verify out-of-bounds exception
        bool caughtException = false;
        try {
            vec.at(5); // Index out of bounds
        } catch (const std::out_of_range& e) {
            caughtException = true;
        }
        assert(caughtException == true);
    }
    std::cout << "PASSED!\n";

    // ----------------------------------------------------
    // TEST 5: Pop Back Operations
    // ----------------------------------------------------
    std::cout << "[Test 5] Testing Pop Back... ";
    {
        CustomVector<int> vec;
        vec.push_back(100);
        vec.push_back(200);

        vec.pop_back();
        assert(vec.getSize() == 1);
        assert(vec[0] == 100);

        vec.pop_back();
        assert(vec.getSize() == 0);
        assert(vec.isEmpty() == true);
    }
    std::cout << "PASSED!\n";

    std::cout << "\n==========================================\n";
    std::cout << "   ALL TESTS COMPLETED SUCCESSFULLY!  \n";
    std::cout << "==========================================\n";
}

int main() {
    runAllTests();
    return 0;
}
```

---

## 6. Beginner Checklist for Verification

Before considering your implementation finished, verify these common pitfalls:

- [ ] **Memory Leaks:** Did you run `delete[] data` in your destructor and inside `resize()`?
- [ ] **Off-by-One Errors:** Does index $0$ hold the first element, and index $(\text{size} - 1)$ hold the last?
- [ ] **Empty Pop Check:** Does `pop_back()` handle popping from an empty vector gracefully without crashing?
- [ ] **Copy/Move Constructors:** If you assign `CustomVector v2 = v1;`, does it create a deep copy or lead to a double-free memory crash? (Tip: Implement deep copy or delete copy constructor for beginners).