# Day 1 Solutions: `MyVector` Implementation & Python Memory Profiler

## Solution 1 (C++): `MyVector` Complete Implementation

```cpp
#include <iostream>
#include <stdexcept>
#include <cassert>

template <typename T>
class MyVector {
private:
    T* data_;
    size_t capacity_;
    size_t size_;

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i]; // Copy elements
        }
        delete[] data_; // Release old heap allocation
        data_ = new_data;
        capacity_ = new_capacity;
    }

public:
    // Default / Parameterized Constructor
    explicit MyVector(size_t initial_capacity = 4)
        : capacity_(initial_capacity), size_(0) {
        data_ = new T[capacity_];
    }

    // Destructor (RAII)
    ~MyVector() {
        delete[] data_;
        data_ = nullptr;
    }

    // Copy Constructor (Deep Copy)
    MyVector(const MyVector& other)
        : capacity_(other.capacity_), size_(other.size_) {
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }

    // Copy Assignment Operator
    MyVector& operator=(const MyVector& other) {
        if (this == &other) return *this; // Self-assignment check

        delete[] data_; // Free existing resource

        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
        return *this;
    }

    // Push Back with Amortized O(1) Growth
    void push_back(const T& value) {
        if (size_ == capacity_) {
            resize(capacity_ * 2);
        }
        data_[size_++] = value;
    }

    // Pop Back
    void pop_back() {
        if (size_ == 0) {
            throw std::underflow_error("Vector is empty!");
        }
        --size_;
    }

    // Accessors
    T& operator[](size_t index) {
        assert(index < size_ && "Index out of bounds!");
        return data_[index];
    }

    const T& operator[](size_t index) const {
        assert(index < size_ && "Index out of bounds!");
        return data_[index];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    bool empty() const { return size_ == 0; }
};

// Driver Test Code
int main() {
    std::cout << "--- Testing MyVector Implementation ---" << std::endl;
    MyVector<int> vec;

    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i * 10);
        std::cout << "Pushed " << i * 10 
                  << " | Size: " << vec.size() 
                  << " | Capacity: " << vec.capacity() << std::endl;
    }

    std::cout << "\nElement at index 4: " << vec[4] << std::endl;

    // Test Copy Constructor
    MyVector<int> vec_copy = vec;
    std::cout << "Copied vector size: " << vec_copy.size() << std::endl;

    std::cout << "All assertions passed successfully!" << std::endl;
    return 0;
}
```

### Compilation & Sanitizer Check Command
```bash
g++ -std=c++17 -O2 -fsanitize=address -g day1_vector.cpp -o day1_vector
./day1_vector
```

---

## Solution 2 (Python): Memory Profiling & PyObject Analysis

```python
import sys
import tracemalloc

def profile_memory():
    print("=== Python Memory Profiling Test ===")
    
    # 1. Individual PyObject Integer Overhead
    sample_int = 42
    print(f"Size of raw integer '42' in Python: {sys.getsizeof(sample_int)} bytes")

    N = 1_000_000

    # 2. Measure List Allocation
    tracemalloc.start()
    int_list = [i for i in range(N)]
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    print(f"\n[List of {N:,} ints]")
    print(f"Peak memory allocation: {peak / (1024 * 1024):.2f} MB")
    print(f"Container direct size (sys.getsizeof): {sys.getsizeof(int_list) / (1024 * 1024):.2f} MB")

    # 3. Measure Tuple Allocation
    tracemalloc.start()
    int_tuple = tuple(range(N))
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    print(f"\n[Tuple of {N:,} ints]")
    print(f"Peak memory allocation: {peak / (1024 * 1024):.2f} MB")

    # 4. Measure Generator Allocation
    tracemalloc.start()
    int_gen = (i for i in range(N))
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()
    print(f"\n[Generator yielding {N:,} ints]")
    print(f"Peak memory allocation: {peak / 1024:.2f} KB (Near Zero!)")

if __name__ == "__main__":
    profile_memory()
```