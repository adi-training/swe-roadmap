# Practice Problem Set: Custom Vectors & Dynamic Arrays

This problem set is divided into three tiers: **Foundational Mechanics**, **In-Place Array Algorithms**, and **Advanced Memory & System Design**. Try working through them on your own before requesting solutions or hints!

---

## Tier 1: Foundational & Low-Level Mechanics

### Problem 1: Explicit Capacity Management (`reserve` and `shrink_to_fit`)
**Objective:** Add fine-grained capacity control to a custom vector class.
* **Task:** Implement two methods:
  1. `void reserve(size_t newCapacity)`: Allocates memory for at least `newCapacity` elements if `newCapacity > capacity`. Does nothing if `newCapacity <= capacity`.
  2. `void shrink_to_fit()`: Reduces capacity to match `size` exactly, freeing unused memory buffer space.
* **Constraint:** Ensure existing element values are preserved during buffer reallocations.

---

### Problem 2: Move Semantics (Move Constructor & Move Assignment)
**Objective:** Avoid expensive deep copies when transferring ownership of dynamic arrays.
* **Task:** Implement the Move Constructor (`CustomVector(CustomVector&& other) noexcept`) and Move Assignment Operator (`CustomVector& operator=(CustomVector&& other) noexcept`).
* **Requirement:** After moving, `other` should be left in a valid empty state (`data = nullptr`, `size = 0`, `capacity = 0`), and ownership of the heap memory buffer must be transferred in $O(1)$ time without copying individual elements.

---

### Problem 3: Custom Iterator Support for Range-Based Loops
**Objective:** Enable modern range-based loop syntax (`for (auto& item : vec)`) on your custom vector.
* **Task:** Implement raw pointer aliases or a simple inner class for `begin()` and `end()`.
* **Goal:** Make the following code compile and run successfully:
  ```cpp
  CustomVector<int> vec = {10, 20, 30};
  for (int x : vec) {
      std::cout << x << " ";
  }
  ```

---

## Tier 2: In-Place Algorithmic Manipulations

### Problem 4: In-Place Duplicate Removal from Sorted Array
**Objective:** Practice the Two-Pointer technique on dynamic buffers.
* **Task:** Given a sorted custom vector, write a function `size_t removeDuplicates(CustomVector<int>& vec)` that removes duplicate elements **in-place**.
* **Constraints:**
  * Must run in $O(N)$ time.
  * Must use $O(1)$ extra auxiliary memory.
  * Return the new effective size of the vector.

---

### Problem 5: Dynamic Array Vector Rotation
**Objective:** Rearrange array elements within contiguous memory without creating secondary arrays.
* **Task:** Implement `void rotateLeft(CustomVector<int>& vec, size_t k)` which shifts all elements to the left by $k$ positions (wrapping around).
* **Example:** `[1, 2, 3, 4, 5]` rotated left by $k = 2$ becomes `[3, 4, 5, 1, 2]`.
* **Constraints:** $O(N)$ time complexity and $O(1)$ additional heap allocation.

---

### Problem 6: Amortized Growth Cost Proof Calculation
**Objective:** Prove mathematical bounds on vector growth factors.
* **Task:** Suppose a custom vector starts with `capacity = 1` and uses a growth multiplier of **$1.5\times$** (rounded up to the nearest integer) instead of $2\times$.
  1. Write out the sequence of capacities as elements are pushed from $N = 1$ to $N = 16$.
  2. Calculate the total number of element copy operations performed during all reallocations combined up to $N = 16$.
  3. Compare the total reallocations against a $2\times$ growth factor.

---

## Tier 3: Advanced Memory Management & System Design

### Problem 7: Placement `new` & Explicit Destructors (Handling Non-Default Constructible Types)
**Objective:** Decouple memory allocation from object construction (how standard library `std::vector` works under the hood).
* **Background:** Standard `new T[capacity]` requires type `T` to have a default constructor.
* **Task:** Re-architect vector memory allocation using raw bytes (`operator new(capacity * sizeof(T))`) combined with **Placement `new`** for element insertion and **explicit destructor calls** (`data[i].~T()`) during deletion/cleanup.

---

### Problem 8: Strong Exception Guarantee on `push_back`
**Objective:** Ensure complete system stability when constructor invocations fail midway through resizing.
* **Scenario:** Suppose type `T`'s copy constructor throws an exception on the $15^{\text{th}}$ element during a `resize()` operation from capacity 10 to 20.
* **Task:** Write the logic for `push_back` such that if an exception is thrown inside `resize()`:
  1. No memory leaks occur.
  2. The original vector remains completely unchanged and valid (Strong Exception Guarantee).

---

### Problem 9: 2D Dynamic Matrix Backed by 1D Vector
**Objective:** Design a flattened cache-friendly 2D data structure.
* **Task:** Design a class `DynamicMatrix<T>` that represents a 2D grid of size $R \times C$, but stores all elements in a single 1D `CustomVector<T>`.
* **Requirements:**
  * Implement indexing `T& at(size_t row, size_t col)`.
  * Implement `void resizeGrid(size_t newRows, size_t newCols)` that preserves existing matrix values at their corresponding grid coordinates.

---

### Problem 10: Dynamic Shrinking Benchmark & Hysteresis Simulation
**Objective:** Detect performance thrashing in dynamic array shrinking algorithms.
* **Task:** Write a test simulator function that performs $1,000,000$ alternating `push_back()` and `pop_back()` operations at the exact capacity threshold.
* **Comparison:** Run the benchmark comparing:
  * **Naive Strategy:** Shrink capacity by half when `size == capacity / 2`.
  * **Hysteresis Strategy:** Shrink capacity by half only when `size == capacity / 4`.
* **Output:** Measure and print total memory reallocation calls for both strategies to demonstrate the efficiency gain of hysteresis.