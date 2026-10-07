# Day 1: Modern C++ Memory Architecture, Pointers, RAII & Engineering Setup

---

## Daily Schedule Breakdown (2 Hours Total)

```
+-----------------------------------------------------------------------------------+
| HOUR 1: STUDY MATERIAL & NOTES TO REMEMBER (60 mins)                             |
|  ├── 1.1 Virtual Memory & C++ Binary Layout (20 mins)                             |
|  ├── 1.2 Pointers, References & Pointer Arithmetic (20 mins)                      |
|  └── 1.3 RAII & Key Interview Rules Cheat Sheet (20 mins)                         |
+-----------------------------------------------------------------------------------+
| HOUR 2: HANDS-ON WORK & INCREMENTAL PROJECT (60 mins)                             |
|  ├── 2.1 Source Code Management & Build Strategy (10 mins)                        |
|  ├── 2.2 Real DSA Problem Solving with Memory Focus (25 mins)                     |
|  └── 2.3 Incremental Project Step 1: TensorCore-CPP Memory Buffer (25 mins)       |
+-----------------------------------------------------------------------------------+
```

---

# HOUR 1: Study Material & Key Notes to Remember

## 1.1 Virtual Memory Layout of a C++ Executable

When your compiled C++ application is loaded into memory, the operating system maps it to a virtual address space. Understanding this layout is essential for writing high-performance robotics and AI applications where latency and cache locality matter.

```
+-----------------------------------+ High Addresses (0x7FFF...)
| Kernel Space                      | (Inaccessible to User Space)
+-----------------------------------+
| Stack                             | Grows Downwards (High -> Low)
|  - Stack Frames (Local variables) |
|  - Function Calls & Return Addrs  |
|                 |                 |
|                 v                 |
|                                   |
|                 ^                 |
|                 |                 |
| Heap                              | Grows Upwards (Low -> High)
|  - Dynamic Allocations (`new`)    |
+-----------------------------------+
| BSS Segment                       | Uninitialized Static/Global Variables
+-----------------------------------+
| Data Segment                      | Initialized Static/Global Variables
+-----------------------------------+
| Text Segment (Code)               | Read-Only Executable Machine Instructions
+-----------------------------------+ Low Addresses (0x0000...)
```

### Memory Segments Explained
1. **Stack:**
   * Allocations take $O(1)$ time by adjusting the stack pointer (`RSP` register).
   * Automatically unwound when execution leaves the current scope.
   * Typical default size: $1\text{ MB} - 8\text{ MB}$. Exceeding this triggers a **Stack Overflow**.
2. **Heap:**
   * Used for dynamic allocations (`new`, `malloc`). Size bounded by physical RAM + Swap space.
   * Slower allocation path because the OS memory allocator must locate contiguous free blocks.
   * Must be explicitly managed; failure leads to **Memory Leaks** or **Dangling Pointers**.
3. **Data & BSS Segments:** Hold global and static variables. `Data` holds initialized variables; `BSS` holds zero-initialized variables.
4. **Text Segment:** Stores raw binary instructions. Read-only to prevent runtime self-modification bugs.

---

## 1.2 Pointer Mechanics, References & Pointer Arithmetic

### Pointers vs. References
* **Raw Pointer (`T*`):** A $64$-bit integer storing a memory address. Can be `nullptr`, re-assigned, and subjected to arithmetic operations.
* **Reference (`T&`):** An explicit alias for an existing object. Cannot be `nullptr` (without undefined behavior) and cannot be re-bound to another object after initialization.

### Pointer Arithmetic Mechanics
When you add an integer $k$ to a pointer `p` of type `T*`, the memory address advances by $k \times \text{sizeof}(T)$ bytes:

$$\text{Address}_{\text{new}} = \text{Address}_{\text{base}} + (k \times \text{sizeof}(T))$$

```cpp
int arr[4] = {10, 20, 30, 40};
int* ptr = arr; // Points to arr[0] at address 0x1000

ptr = ptr + 2;  // Advances by 2 * sizeof(int) = 8 bytes.
// ptr now points to arr[2] at address 0x1008 (*ptr == 30)
```

---

## 1.3 RAII (Resource Acquisition Is Initialization) Pattern

RAII is the core memory safety design pattern in modern C++. It dictates that **resource ownership (heap memory, file handles, sockets) must be bound to the stack lifecycle of an object**.

### Bad (Manual Lifetime Management):
```cpp
void processData() {
    int* raw_array = new int[1000];
    if (computeFailed()) {
        return; // CRITICAL BUG: Memory leak! delete[] is bypassed.
    }
    delete[] raw_array;
}
```

### Good (RAII Management):
```cpp
template <typename T>
class ScopedArray {
private:
    T* ptr_;
public:
    explicit ScopedArray(size_t size) : ptr_(new T[size]) {}
    ~ScopedArray() { delete[] ptr_; } // Destructor guaranteed to run on exit!

    T& operator[](size_t index) { return ptr_[index]; }
    
    // Prevent unsafe copying (Rule of Three/Five preview)
    ScopedArray(const ScopedArray&) = delete;
    ScopedArray& operator=(const ScopedArray&) = delete;
};
```

---

## 📌 Key Notes & Rules to Remember (Interview Checklist)

1. **Size Rules:** On $64$-bit systems, all pointers (`int*`, `double*`, `void*`) take exactly $8$ bytes ($64$ bits), regardless of the data type they point to.
2. **`nullptr` Safety:** Always initialize uninitialized raw pointers to `nullptr`. Always check `if (ptr != nullptr)` before dereferencing if non-null guarantee isn't provided by structure.
3. **Array Allocation Deletion:** If allocated with `new T[size]`, you **must** deallocate with `delete[] ptr`. Using `delete ptr` on an array causes undefined behavior.
4. **Cache Locality:** Contiguous memory arrays (`std::vector`, raw arrays) drastically outperform linked data structures (`std::list`) in iteration loops because CPU L1/L2 cache lines pre-fetch contiguous memory blocks ($64$ bytes per cache line).
5. **Python Overhead Contrast:** In Python, an integer is a `PyObject` structure requiring $28$ bytes of metadata header space, whereas a C++ primitive `int32_t` takes exactly $4$ bytes.

---

# HOUR 2: Hands-On Execution & Incremental Project

## 2.1 Source Code Management & Engineering Workflow

To prepare for professional software development and interview standard quality, maintain a clean project structure with static checking and sanitizers.

### Recommended Repository Layout
```
maang-prep/
├── README.md
├── Makefile
├── dsa/
│   ├── day01_concatenation.cpp
│   └── day01_remove_duplicates.cpp
└── project/
    └── tensor_core/
        ├── include/
        │   └── memory_buffer.hpp
        ├── src/
        │   └── memory_buffer.cpp
        └── main.cpp
```

### Modern C++ Compiler Configuration (`Makefile`)
Always compile with standard warning flags and AddressSanitizer (`ASan`) enabled during development to catch memory leaks immediately:

```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -g -fsanitize=address,undefined

all: dsa_day1 project_day1

dsa_day1: dsa/day01_concatenation.cpp dsa/day01_remove_duplicates.cpp
	$(CXX) $(CXXFLAGS) dsa/day01_concatenation.cpp -o build/day01_concat
	$(CXX) $(CXXFLAGS) dsa/day01_remove_duplicates.cpp -o build/day01_remove_dup

project_day1: project/tensor_core/main.cpp
	$(CXX) $(CXXFLAGS) -Iproject/tensor_core/include project/tensor_core/src/memory_buffer.cpp project/tensor_core/main.cpp -o build/tensor_core_day1

clean:
	rm -rf build/*
```

---

## 2.2 Real DSA Problems to Solve

### Problem 1: Array Allocation & Memory Copy Optimization
* **Problem:** LeetCode 1929 - Concatenation of Array
* **Goal:** Given an integer array `nums` of length $n$, return an array `ans` of length $2n$ where `ans[i] == nums[i]` and `ans[i + n] == nums[i]`.
* **Constraint:** Optimize pointer copying and pre-allocate total contiguous memory block in C++.

#### C++ Implementation:
```cpp
#include <iostream>
#include <vector>
#include <cstring>

class Solution {
public:
    std::vector<int> getConcatenation(const std::vector<int>& nums) {
        const size_t n = nums.size();
        std::vector<int> ans;
        
        // Optimization: Reserve contiguous block upfront to avoid re-allocations
        ans.reserve(2 * n);
        
        // Fast memory copying
        ans.insert(ans.end(), nums.begin(), nums.end());
        ans.insert(ans.end(), nums.begin(), nums.end());
        
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 1};
    std::vector<int> result = sol.getConcatenation(nums);

    std::cout << "Concatenated Array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

---

### Problem 2: In-Place Two-Pointer Array Mutation
* **Problem:** LeetCode 26 - Remove Duplicates from Sorted Array
* **Goal:** Remove duplicates in-place such that each unique element appears only once. Return $k$ (number of unique elements). Space complexity must be $O(1)$.

#### C++ Implementation:
```cpp
#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        size_t write_index = 1; // Slow pointer tracking write location

        for (size_t read_index = 1; read_index < nums.size(); ++read_index) {
            if (nums[read_index] != nums[read_index - 1]) {
                nums[write_index] = nums[read_index];
                write_index++;
            }
        }
        return static_cast<int>(write_index);
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k = sol.removeDuplicates(nums);

    std::cout << "Unique count k = " << k << "\nModified Array: ";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    assert(k == 5);
    return 0;
}
```

---

## 2.3 Incremental Project: `TensorCore-CPP`

### Project Vision (52-Week Cumulative Build)
You are building **`TensorCore-CPP`**: A high-performance, low-latency C++ Machine Learning Tensor Library with custom memory management, SIMD vectorization, autograd engine, and CUDA/C++ inference API tailored for robotics/edge computing.

---

### Day 1 Step: SIMD-Aligned RAII Memory Buffer (`AlignedMemoryBuffer`)

To run high-speed SIMD vector instructions (AVX-256 / AVX-512) for AI operations, memory buffers **must be aligned to 32-byte or 64-byte boundaries**. Standard `new` or `malloc` does not guarantee 64-byte alignment.

#### Header File (`project/tensor_core/include/memory_buffer.hpp`)
```cpp
#ifndef MEMORY_BUFFER_HPP
#define MEMORY_BUFFER_HPP

#include <cstddef>
#include <cstdint>
#include <stdexcept>

class AlignedMemoryBuffer {
private:
    float* data_;
    size_t size_;
    size_t alignment_;

public:
    // Constructor allocates aligned memory
    AlignedMemoryBuffer(size_t size, size_t alignment = 64);

    // Destructor cleanly frees memory
    ~AlignedMemoryBuffer();

    // Prevent implicit copies to enforce RAII pointer ownership
    AlignedMemoryBuffer(const AlignedMemoryBuffer&) = delete;
    AlignedMemoryBuffer& operator=(const AlignedMemoryBuffer&) = delete;

    // Element Access
    float& operator[](size_t index);
    const float& operator[](size_t index) const;

    // Getters
    float* data() { return data_; }
    const float* data() const { return data_; }
    size_t size() const { return size_; }
    size_t alignment() const { return alignment_; }
};

#endif // MEMORY_BUFFER_HPP
```

#### Source Implementation (`project/tensor_core/src/memory_buffer.cpp`)
```cpp
#include "memory_buffer.hpp"
#include <cstdlib>
#include <iostream>

AlignedMemoryBuffer::AlignedMemoryBuffer(size_t size, size_t alignment)
    : size_(size), alignment_(alignment) {
    
    // Allocate 64-byte cache-aligned memory block
#if defined(_MSC_VER)
    data_ = static_cast<float*>(_aligned_malloc(size_ * sizeof(float), alignment_));
    if (!data_) throw std::bad_alloc();
#else
    void* ptr = nullptr;
    if (posix_memalign(&ptr, alignment_, size_ * sizeof(float)) != 0) {
        throw std::bad_alloc();
    }
    data_ = static_cast<float*>(ptr);
#endif

    // Zero-initialize memory block
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = 0.0f;
    }
}

AlignedMemoryBuffer::~AlignedMemoryBuffer() {
    if (data_) {
#if defined(_MSC_VER)
        _aligned_free(data_);
#else
        free(data_);
#endif
        data_ = nullptr;
    }
}

float& AlignedMemoryBuffer::operator[](size_t index) {
    if (index >= size_) throw std::out_of_range("Buffer index out of bounds!");
    return data_[index];
}

const float& AlignedMemoryBuffer::operator[](size_t index) const {
    if (index >= size_) throw std::out_of_range("Buffer index out of bounds!");
    return data_[index];
}
```

#### Driver Verification Script (`project/tensor_core/main.cpp`)
```cpp
#include "memory_buffer.hpp"
#include <iostream>
#include <cstdint>

int main() {
    std::cout << "=== TensorCore-CPP: Day 1 Memory Buffer Verification ===" << std::endl;

    size_t elements = 1024;
    size_t alignment = 64; // 64-byte alignment for AVX-512

    AlignedMemoryBuffer buffer(elements, alignment);

    // Verify address alignment constraint
    uintptr_t raw_address = reinterpret_cast<uintptr_t>(buffer.data());
    std::cout << "Allocated Memory Address: 0x" << std::hex << raw_address << std::dec << std::endl;

    if (raw_address % alignment == 0) {
        std::cout << "SUCCESS: Memory is correctly aligned to " << alignment << " bytes!" << std::endl;
    } else {
        std::cerr << "FAILURE: Memory address is misaligned!" << std::endl;
        return 1;
    }

    // Assign & verify data
    buffer[0] = 3.14159f;
    buffer[1023] = 2.71828f;

    std::cout << "buffer[0] = " << buffer[0] << std::endl;
    std::cout << "buffer[1023] = " << buffer[1023] << std::endl;

    std::cout << "Day 1 Project Module Verified Cleanly!" << std::endl;
    return 0;
}
```