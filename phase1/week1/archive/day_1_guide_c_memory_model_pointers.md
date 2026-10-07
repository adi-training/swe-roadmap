# Day 1 Guide: C++ Memory Model, Pointers & Python Memory Basics

## Learning Objectives
1. Understand how memory is organized in a C++ executable (Text, Data, BSS, Stack, Heap).
2. Master explicit pointer operations, address-of operator (`&`), dereferencing (`*`), and pointer arithmetic.
3. Understand Dynamic Memory Allocation (`new`/`delete` vs. `malloc`/`free`) and Resource Acquisition Is Initialization (RAII).
4. Contrast raw pointers with C++ Smart Pointers (`std::unique_ptr`, `std::shared_ptr`).
5. Gain foundational insight into Python's object overhead, reference counting, and garbage collector.

---

## 1. C++ Executable Memory Layout

When a binary runs, OS virtual memory assigns the program a virtual address space:

```
+-----------------------------------+ High Memory Addresses
| Stack Frame (Local variables)     |  |
|   |  v (Grows Downward)          |  v
|                                   |
|   ^  | (Grows Upward)            |  ^
| Heap (Dynamic allocations)        |  |
+-----------------------------------+
| BSS Segment (Uninitialized static)|
+-----------------------------------+
| Data Segment (Initialized static) |
+-----------------------------------+
| Text Segment (Compiled Instructions)| Low Memory Addresses
+-----------------------------------+
```

### Stack Memory
* **Allocation Speed:** Extremely fast ($O(1)$ stack pointer adjustment).
* **Lifetime:** Managed automatically by scope; destroyed when function frame pops.
* **Size Limit:** Small (typically 1MB - 8MB). Exceeding this causes **Stack Overflow**.

### Heap Memory
* **Allocation Speed:** Slower (requires finding contiguous free memory blocks via the OS heap allocator).
* **Lifetime:** Manual / Dynamic. Persists until explicitly freed.
* **Risk:** Memory leaks, dangling pointers, heap fragmentation.

---

## 2. Dynamic Memory & RAII Pattern

### Manual Allocation Danger
```cpp
void badMemoryManagement() {
    int* ptr = new int[100]; // Allocation on Heap
    if (someCondition()) {
        return; // LEAK! free/delete was bypassed!
    }
    delete[] ptr;
}
```

### RAII Solution (Resource Acquisition Is Initialization)
Bind lifetime of heap resources to stack-allocated wrapper object's lifetime:

```cpp
template <typename T>
class RAIIWrapper {
private:
    T* data;
public:
    explicit RAIIWrapper(size_t size) : data(new T[size]) {}
    ~RAIIWrapper() { delete[] data; } // Automatically freed when object drops out of scope!
    T& operator[](size_t idx) { return data[idx]; }
};
```

---

## 3. Pointer Mechanics Checklist

* **Raw Pointer:** `int* p = &var;` Stores raw memory address ($64$-bit integer on 64-bit platforms).
* **Reference:** `int& ref = var;` An alias for an existing object. Cannot be `nullptr`; cannot be re-bound.
* **Pointer Arithmetic:** `p + 1` advances the address by `sizeof(T)` bytes.
  $$\text{Address}_{\text{new}} = \text{Address}_{\text{old}} + (k \times \text{sizeof}(T))$$

---

## 4. Python Memory Model Overview

In Python, **everything is a pointer to a `PyObject`**.

```
Python variable name  --->  [ PyObject Struct ]
                            ├── ob_refcnt  (Reference count)
                            ├── ob_type    (Pointer to type object)
                            └── ob_ival    (Actual payload value)
```

An `int` in C++ takes $4$ bytes ($32$ bits). In Python, a simple integer takes $28$ bytes due to `PyObject` header overhead!