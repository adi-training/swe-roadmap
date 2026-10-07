# Day 3 Master Guide: Stacks, Queues & Circular Buffers

Welcome to Day 3 of the C++ Systems & DSA Mastery Series! Today, we explore two fundamental Abstract Data Types (ADTs)—**Stacks (LIFO)** and **Queues (FIFO)**—along with low-level **Circular Ring Buffers** and advanced **Monotonic Data Structures**.

This guide is designed for developers with an intermediate understanding of C++ who want to understand *how* these structures work at the memory level and *why* specific engineering choices are made in real-world systems.

---

## 1. Fundamentals & Core Invariants

### What are Abstract Data Types (ADTs)?
An **Abstract Data Type (ADT)** defines a data structure purely by its **behavior and invariants** from the perspective of a user, rather than its internal memory implementation. 

* **Stack (LIFO - Last In, First Out):** The element added most recently is the first to be removed. Think of a stack of cafeteria trays.
* **Queue (FIFO - First In, First Out):** The element added earliest is the first to be removed. Think of a line of people waiting for a ticket counter.

```
STACK (LIFO Invariant)                QUEUE (FIFO Invariant)
Push(10), Push(20), Push(30)          Enqueue(10), Enqueue(20), Enqueue(30)

     +----+                                    Front                Back
Top  | 30 |  <-- Pop() removes 30              +----+----+----+
     +----+                                    | 10 | 20 | 30 |
     | 20 |                                    +----+----+----+
     +----+                                      ^          ^
     | 10 |                                    Dequeue()   Enqueue()
     +----+                                    removes 10  adds at back
```

---

## 2. Real-World & Operating System Applications

Why are Stacks and Queues essential in system development and algorithmic processing?

| Context | Application | Structure Used | Invariant / Reason |
| :--- | :--- | :--- | :--- |
| **Compiler & CPU** | Function Call Stack & Recursion | Stack | LIFO tracks return addresses, local variables, and frame scope. |
| **Text Editors** | Undo / Redo Mechanism | Two Stacks | Action stack (Undo) and inverted stack (Redo). |
| **Parsing & Compilers** | Expression evaluation, Bracket matching | Stack | Context-free grammar parsing (RPN, AST traversal). |
| **Operating Systems** | CPU Task Scheduling & Process Queues | Queue / Priority Queue | Round-robin execution demands strict FIFO arrival order. |
| **Networking & I/O** | Packet Buffers, Socket RX/TX Buffers | Circular Ring Buffer | Fixed memory footprint prevents heap allocation under heavy traffic. |
| **Graph Algorithms** | Breadth-First Search (BFS) | Queue | Level-order traversal requires processing nodes in order of discovery. |

---

## 3. C++ STL Container Adaptors & Memory Architectures

In the C++ Standard Template Library (STL), `std::stack` and `std::queue` are **Container Adaptors**, not independent standalone data structures.

### What is a Container Adaptor?
A container adaptor takes an existing sequential container (such as `std::deque` or `std::vector`) and restricts its public interface to expose only LIFO or FIFO operations.

```cpp
// Explicitly specifying the underlying container:
std::stack<int, std::vector<int>>  vectorBackedStack;
std::queue<int, std::list<int>>    listBackedQueue;

// Default STL definitions:
template <class T, class Container = std::deque<T>> class stack;
template <class T, class Container = std::deque<T>> class queue;
```

---

### Deep Dive: Memory Trade-Offs of Underlying Backing Containers

Why does C++ use `std::deque` by default instead of `std::vector` or `std::list`? Let's compare their layout mechanics:

```
1. std::vector (Contiguous Array)
   [ 10 | 20 | 30 | 40 | 50 | -- | -- ]
   - Cache Locality: EXCELLENT (contiguous cache lines)
   - Push/Pop Back:  O(1) amortized
   - Pop Front:      O(N) (Requires shifting all remaining elements left)

2. std::list (Doubly-Linked List)
   [Head] <-> [Node: 10] <-> [Node: 20] <-> [Node: 30] <-> [Tail]
   - Cache Locality: POOR (pointer chasing across heap memory)
   - Memory Overhead: HIGH (16 bytes of prev/next pointers per element)
   - Push/Pop Ends:  O(1) strict

3. std::deque (Double-Ended Queue - Array of Fixed Chunks)
   Map Array: [Ptr0] [Ptr1] [Ptr2]
                |      |
                v      v
              [Chunk 0: 512 Bytes] -> [ 10 | 20 | 30 ]
              [Chunk 1: 512 Bytes] -> [ 40 | 50 | 60 ]
   - Cache Locality: VERY GOOD (chunk-local contiguity)
   - Push/Pop Ends:  O(1) strict without element shifting
   - Dynamic Growth: Allocates new chunks without reallocating existing data
```

### Architectural Comparison Matrix

| Container Feature | `std::vector` | `std::list` | `std::deque` (Default) |
| :--- | :--- | :--- | :--- |
| **Spatial Cache Locality** | Highest (100% contiguous) | Lowest (Heap fragmented) | High (Contiguous within chunks) |
| **Front Deletion Cost** | $O(N)$ (Triggers copy/shift) | $O(1)$ | $O(1)$ |
| **Growth Mechanism** | Reallocates & copies all elements | Heap allocates per node | Allocates new fixed chunk |
| **Iterator Invalidation** | High (on reallocation) | Low (never invalidates un-popped) | Medium (at ends only) |
| **Best Choice For...** | Stacks requiring max cache speed | Rare / Specific node requirements | Default for both Stacks & Queues |

---

## 4. Deep Dive: Circular Ring Buffers (Circular Queues)

In embedded systems, audio processing, and high-frequency trading (HFT), allocating memory dynamically on the heap during operation is unacceptable due to non-deterministic latencies.

A **Circular Ring Buffer** provides a fixed-size FIFO queue using a contiguous array without needing to shift elements when items are dequeued.

### The Naive Array Queue Problem
If we use a standard array for a queue without circular wrapping:

```
Initial State:   [ 10 | 20 | 30 | -- | -- ]   (Head=0, Tail=3)
Pop 10 & 20:     [ -- | -- | 30 | -- | -- ]   (Head=2, Tail=3)
Push 40, 50:     [ -- | -- | 30 | 40 | 50 ]   (Head=2, Tail=5 - Array FULL!)
```
Notice that indices `0` and `1` are wasted, even though space is available. Shifting elements to the left takes $O(N)$ time.

---

### The Circular Solution: Modulo Index Arithmetic
By wrapping pointer indices using modulo division (`% Capacity`), the array seamlessly connects end-to-front:

```
Indices:         [  0  ] [  1  ] [  2  ] [  3  ] [  4  ]
Values:          [  E  ] [  F  ] [     ] [  C  ] [  D  ]
                            ^                 ^
                           Tail              Head

Head = 3 (First element to dequeue: C)
Tail = 2 (Next available position to enqueue)
Current Size = 4, Capacity = 5
```

#### Step-by-Step Index Updates:
$$\text{Next Tail Position} = (\text{Tail} + 1) \pmod{\text{Capacity}}$$
$$\text{Next Head Position} = (\text{Head} + 1) \pmod{\text{Capacity}}$$

---

### High-Performance Bitwise Mask Optimization

Modulo division (`%`) requires a hardware integer division instruction, which takes multiple CPU clock cycles. When the buffer capacity $C$ is guaranteed to be a **Power of Two** ($C = 2^k$, e.g., 4, 8, 16, 1024, 4096), we can replace the modulo operation with a **bitwise AND mask**.

#### Mathematical Proof:
If $C = 2^k$, then $C - 1$ produces a binary mask where all bits lower than $2^k$ are set to `1`.
For example, if $C = 8 \ (1000_2)$, then $C - 1 = 7 \ (0111_2)$.

$$\text{index} \pmod{2^k} \equiv \text{index} \ \& \ (2^k - 1)$$

#### Binary Example ($C = 8$, Mask $= 7$):
* Moving from index $7$ to $8$:
  * $8 \pmod 8 = 0$
  * $8 \ \& \ 7 = 1000_2 \ \& \ 0111_2 = 0000_2 = 0$ (Correctly wrapped to 0!)
* Moving from index $5$ to $6$:
  * $6 \pmod 8 = 6$
  * $6 \ \& \ 7 = 0110_2 \ \& \ 0111_2 = 0110_2 = 6$

> **Performance Impact:** Bitwise `AND` takes **1 clock cycle** on modern CPUs, whereas `DIV/MOD` can take 10–20 cycles.

---

### Disambiguating Full vs. Empty Buffer States

When `Head == Tail`, the buffer could be **completely empty** or **completely full**. There are two standard approaches to solve this ambiguity:

1. **Maintain an explicit `size` variable (Recommended for clarity):**
   * `Empty`: `size == 0`
   * `Full`: `size == capacity`
2. **Sacrifice one array slot:**
   * Keep one slot permanently blank.
   * `Empty`: `Head == Tail`
   * `Full`: `(Tail + 1) % Capacity == Head`

---

## 5. Advanced Pattern: Monotonic Data Structures

A **Monotonic Data Structure** maintains its elements in strict sorted order (either strictly increasing or strictly decreasing) at all times during updates.

It achieves this by popping out all elements that violate the desired order *before* inserting a new element.

```
Monotonic Increasing Stack: Elements increase from top to bottom.
Monotonic Decreasing Stack: Elements decrease from top to bottom.
```

### Why Use Monotonic Stacks? ($O(N^2) \rightarrow O(N)$ Acceleration)
Consider the problem: *"For each element in an array, find the first element to its right that is larger than it."*

* **Naive Approach:** For each element $i$, loop through all elements $j > i$ to find the first larger value.
  * Time Complexity: $O(N^2)$ nested loops.
* **Monotonic Stack Approach:** Push elements onto a stack. Whenever a new number is larger than the stack's top element, it acts as the "next greater element" for everything popped!
  * Time Complexity: **Amortized $O(N)$**, because every element is pushed onto the stack exactly once and popped at most once.

---

### Walkthrough: Monotonic Decreasing Stack (Next Greater Element)

Let's trace array `[13, 7, 6, 12]` step-by-step to find the Next Greater Element for each index.

We maintain a **Monotonic Decreasing Stack** storing element indices.

```
Input Array:  [ 13,   7,   6,  12 ]
Indices:        0     1    2    3

Trace Step-by-Step:

Step 1: i = 0 (Val = 13)
        Stack is empty.
        Push Index 0.
        Stack State (Indices): [0] (Val: 13)

Step 2: i = 1 (Val = 7)
        Compare Val 7 with Stack Top (Val 13): 7 <= 13. Order maintained.
        Push Index 1.
        Stack State (Indices): [0, 1] (Vals: 13, 7)

Step 3: i = 2 (Val = 6)
        Compare Val 6 with Stack Top (Val 7): 6 <= 7. Order maintained.
        Push Index 2.
        Stack State (Indices): [0, 1, 2] (Vals: 13, 7, 6)

Step 4: i = 3 (Val = 12)
        Compare Val 12 with Stack Top (Val 6): 12 > 6! -> VIOLATION!
        -> Pop Index 2 (Val 6). Next Greater Element for 6 is 12!
        
        Compare Val 12 with new Stack Top (Val 7): 12 > 7! -> VIOLATION!
        -> Pop Index 1 (Val 7). Next Greater Element for 7 is 12!
        
        Compare Val 12 with new Stack Top (Val 13): 12 <= 13. Order maintained.
        Push Index 3.
        Stack State (Indices): [0, 3] (Vals: 13, 12)

Step 5: End of Array reached. Remaining indices in stack [0, 3] have NO greater element -> Assign -1.

Final Output Mapping:
- Val 13 -> None (-1)
- Val  7 -> 12
- Val  6 -> 12
- Val 12 -> None (-1)
```

---

### Monotonic Queue (Sliding Window Maximum)

When finding the minimum or maximum element across a moving dynamic range (a sliding window of size $k$), a **Monotonic Deque (Double-Ended Queue)** allows maintaining window extrema in $O(1)$ time per slide.

```
Window slides right -> 
[ 1  3 -1 ] -3  5  3  6  7   -> Max in window: 3
 1 [ 3 -1  -3 ] 5  3  6  7   -> Max in window: 3
 1  3 [-1  -3  5 ] 3  6  7   -> Max in window: 5
```

#### Deque Invariants:
1. **Front of Deque:** Always holds the index of the maximum element in the current window.
2. **Back of Deque:** Maintains monotonic decreasing order. Smaller, older elements that can never become the window maximum are popped from the back before inserting the current index.
3. **Out-of-Bounds Removal:** Indices that fall outside the left side of the sliding window boundary are popped from the front.

---

## 6. Summary Decision Checklist

Use this cheat sheet to choose the right structure during technical interviews or systems architectural design:

```
                            Decision Flowchart
                            ------------------
                                   |
                  Is dynamic ordering needed?
                 /                            \
              YES                              NO
              /                                  \
   Need Range Min/Max over              Need LIFO or FIFO access?
   a window or next greater?               /                  \
         /            \                LIFO                    FIFO
     Window         Next Element       /                          \
       |                 |       Need high cache           Need fixed-size
  Monotonic         Monotonic    locality/vector?          zero-alloc ring?
    Deque             Stack        /        \                 /         \
                                 YES        NO              YES          NO
                                 /            \             /              \
                           std::vector    std::stack    Ring Buffer     std::queue
                           (or Adaptor)  (std::deque)  (Power of 2)    (std::deque)
```

### Complexity Quick-Reference

| Structure | Enqueue / Push | Dequeue / Pop | Access Top / Front | Space Complexity |
| :--- | :--- | :--- | :--- | :--- |
| **`std::stack`** | $O(1)$ amortized | $O(1)$ | $O(1)$ | $O(N)$ |
| **`std::queue`** | $O(1)$ amortized | $O(1)$ | $O(1)$ | $O(N)$ |
| **Circular Ring Buffer** | $O(1)$ strict | $O(1)$ strict | $O(1)$ strict | $O(C)$ fixed |
| **Monotonic Stack** | $O(1)$ amortized | $O(1)$ amortized | $O(1)$ | $O(N)$ total across array |
| **Monotonic Deque** | $O(1)$ amortized | $O(1)$ amortized | $O(1)$ front | $O(K)$ window size |