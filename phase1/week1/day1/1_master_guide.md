# Day 1: C++ Pointer Mechanics, Memory Layout & Dynamic Array Basics

---

## 🕒 Daily Schedule Overview (120 Minutes)

```
+-----------------------------------------------------------------------------------+
| HOUR 1: STUDY MATERIAL & INTERVIEW NOTES (60 mins)                                |
|  ├── 1.1 Executable Memory Layout: Stack vs. Heap (20 mins)                        |
|  ├── 1.2 Pointer Math, References & Dereferencing Rules (20 mins)                 |
|  └── 1.3 STL Mechanics: `std::vector` Under the Hood & Notes (20 mins)            |
+-----------------------------------------------------------------------------------+
| HOUR 2: HANDS-ON WORK & INCREMENTAL PROJECT (60 mins)                             |
|  ├── 2.1 Tooling & Engineering Environment Setup (10 mins)                        |
|  ├── 2.2 Real DSA Problems: Array Mutation & Pointer Scanners (25 mins)           |
|  └── 2.3 Incremental Project Step 1: `CustomVector<T>` from Scratch (25 mins)    |
+-----------------------------------------------------------------------------------+
```

---

# HOUR 1: Study Material & Key Notes

## 1.1 Executable Memory Layout: Stack vs. Heap

When a C++ program runs, the operating system assigns it a virtual address space split into distinct regions:

```
  High Addresses (0x7FFF...)
  +-----------------------------------+
  | Kernel Space                      | (Inaccessible to user mode)
  +-----------------------------------+
  | Stack Segment                     | Grows Downward
  |  - Local variables & frames       |
  |  - Function calls & return addrs  |
  |                 |                 |
  |                 v                 |
  |                                   |
  |                 ^                 |
  |                 |                 |
  | Heap Segment                      | Grows Upward
  |  - Dynamic memory (`new`, `malloc`)|
  +-----------------------------------+
  | BSS Segment                       | Uninitialized global/static variables
  +-----------------------------------+
  | Data Segment                      | Initialized global/static variables
  +-----------------------------------+
  | Text Segment                      | Read-only machine code instructions
  +-----------------------------------+
  Low Addresses (0x0000...)
```

### Critical Comparison Table

| Metric | Stack Memory | Heap Memory |
| :--- | :--- | :--- |
| **Allocation Mechanism** | Stack Pointer (`RSP`) shift | Allocator search (`ptmalloc`, `jemalloc`) |
| **Speed** | Extremely fast ($O(1)$) | Slower ($O(1)$ amortized to $O(N)$) |
| **Lifetime Management** | Automatic (RAII / Scope exit) | Manual (`delete` / `delete[]` / Smart Pointers) |
| **Size Limit** | Small ($1\text{ MB} - 8\text{ MB}$) | Bound by available RAM + Swap |
| **Primary Danger** | **Stack Overflow** (recursion/huge arrays) | **Memory Leaks / Use-After-Free** |

---

## 1.2 Pointer Math, References & Dereferencing Rules

### Pointers vs. References
* **Pointer (`T* p`):** Stores a $64$-bit memory address. Can be `nullptr`, re-assigned to point elsewhere, and supports arithmetic.
* **Reference (`T& r`):** An alias for an existing object. Must be initialized upon creation, cannot be `nullptr`, and cannot be rebound.

### Pointer Arithmetic Formula
When adding an integer $k$ to pointer $p$ of type `T*`:

$$\text{Address}(p + k) = \text{Address}(p) + (k \times \text{sizeof}(T))$$

```cpp
int arr[4] = {10, 20, 30, 40};
int* p = arr; // Points to arr[0] at address 0x1000 (example)

p = p + 2;    // Address becomes 0x1000 + (2 * sizeof(int)) = 0x1008
// *p now evaluates to 30
```

---

## 1.3 STL Mechanics: `std::vector` Internal Architecture

`std::vector<T>` is a contiguous array wrapper managing memory dynamically on the Heap using three raw pointers internally:

```
  std::vector<int> v;  // Stack object containing 3 pointers (24 bytes total)
  
  Stack:
  +-------------------+
  | m_start           |------> Heap: [ 10 | 20 | 30 |    |    ]
  | m_finish          |----------------------------^ (size = 3)
  | m_end_of_storage  |----------------------------------^ (capacity = 5)
  +-------------------+
```

### Amortized $O(1)$ Growth Strategy
1. When `m_finish == m_end_of_storage`, inserting an element triggers reallocation.
2. A new memory block of $2\times$ capacity (or $1.5\times$ in MSVC) is allocated on the Heap.
3. Existing elements are copied/moved to the new block.
4. Old heap block is deleted, and internal pointers update.

---

## 📌 Key Interview Rules & Checklist

1. **Alignment & Size:** On 64-bit systems, all pointers (`int*`, `void*`, `double*`) take **8 bytes**, regardless of what type they point to.
2. **`nullptr` Safety:** Always initialize pointers to `nullptr` if they don't point to valid memory yet.
3. **Array Deallocation Match:** Allocating with `new T[size]` requires deallocating with `delete[] ptr`. Using scalar `delete ptr` triggers **Undefined Behavior**.
4. **Pointer Invalidation:** Operations that reallocate a container (like `push_back`) invalidate all existing pointers and references to its elements.
5. **AddressSanitizer:** Always compile locally with `-fsanitize=address -g` to detect buffer overflows and memory leaks instantly during execution.

---

# HOUR 2: Hands-On Work & Incremental Project

## 2.1 Repository Setup

```
day01/
├── Makefile
├── src/
│   ├── dsa_solutions.cpp
│   └── custom_vector.hpp
└── tests/
    └── test_custom_vector.cpp
```

---

## 2.2 DSA Problems (Pointer Scanners)

### Problem 1: [LeetCode 27 — Remove Element](https://leetcode.com/problems/remove-element/)
* **Goal:** Remove all occurrences of `val` in `nums` in-place. Return count of remaining elements $k$.
* **Approach:** Two-pointer fast/slow write pointer technique ($O(N)$ time, $O(1)$ space).

### Problem 2: LeetCode 26 — [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array)
* **Goal:** Remove duplicate elements in-place from a sorted array.
* **Approach:** Two-pointer read/write index technique ($O(N)$ time, $O(1)$ space).

---

## 2.3 Incremental Project: Step 1 — `CustomVector<T>`

Building a dynamic array from scratch to master pointer allocation, reallocation strategies, and basic RAII principles.

* Key Features in Step 1:
  * Raw pointer buffer `m_data` management using `new[]` and `delete[]`.
  * Dynamic reallocation ($2\times$ growth factor) on capacity exhaust.
  * Indexing operator `[]` overload.
  * Basic move semantics in reallocation.