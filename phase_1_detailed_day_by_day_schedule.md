# Phase 1: Day-by-Day Micro-Schedule (Weeks 1 to 12)

## Week 1: Python Production & Modern C++ STL Mastery

* **Day 1 (Mon):**
  * *Theory (25m):* Stack vs. Heap allocation, RAII, raw pointers vs. smart pointers (`std::unique_ptr`, `std::shared_ptr`).
  * *Hands-on (1h 35m):* Write a C++ dynamic array (`MyVector`) with raw memory management, dynamic re-allocation, copy constructors, and destructor.
* **Day 2 (Tue):**
  * *Theory (25m):* Internal mechanics of `std::vector`, `std::unordered_map` (hash collision strategies), and `std::priority_queue`.
  * *Hands-on (1h 35m):* Benchmark spatial locality and cache hit efficiency of `std::vector<int>` vs. `std::list<int>` in C++.
* **Day 3 (Wed):**
  * *Theory (25m):* Python memory model, reference counting, generational garbage collector, GIL implications.
  * *Hands-on (1h 35m):* Build custom Python classes using `@dataclass`, typing annotations, and dunder methods (`__getitem__`, `__len__`). Profile memory using `sys.getsizeof` and `tracemalloc`.
* **Day 4 (Thu):**
  * *Theory (25m):* Lvalues vs. Rvalues, move semantics, `std::move`, `std::forward`.
  * *Hands-on (1h 35m):* Implement move constructors and move assignment operators for `MyVector`. Measure speed improvement during reallocation.
* **Day 5 (Fri):**
  * *Theory (25m):* Python concurrency: `asyncio` event loop vs. `threading` vs. `multiprocessing`.
  * *Hands-on (1h 35m):* Build an asynchronous Python data downloader using `asyncio` and `aiohttp` with structured error logging.
* **Day 6 (Sat - 5.5h):**
  * *Deep Build:* Implement a thread-safe `SharedPointer<T>` from scratch in C++ using atomic reference counts (`std::atomic<size_t>`).
* **Day 7 (Sun - 5.5h):**
  * *Timed Drill:* Solve LeetCode 1 (Two Sum), 217 (Contains Duplicate), 242 (Valid Anagram), and 125 (Valid Palindrome) in C++. Focus on passing by `const` reference and minimizing dynamic heap allocations.

---

## Weeks 2–3: Two Pointers, Sliding Window & Arrays

* **Week 2 (Mon–Fri):**
  * *Mon:* Two-pointer technique (LC 167, LC 977, LC 283).
  * *Tue:* In-place array operations & cycle sort pattern (LC 189, LC 41, LC 448).
  * *Wed:* Python string slicing and manipulation algorithms (LC 680, LC 8).
  * *Thu:* Fixed-size sliding window mechanics (LC 643, LC 1456, LC 438).
  * *Fri:* Variable-size sliding window mechanics (LC 3, LC 209, LC 1004).
* **Week 2 (Sat–Sun):**
  * *Sat:* Hard sliding window & two-pointer drill (LC 76 Minimum Window Substring, LC 42 Trapping Rain Water).
  * *Sun:* 4-problem timed array sprint (20-minute limit per problem).

* **Week 3 (Mon–Fri):**
  * *Mon:* Prefix Sum arrays & 2D Range Queries (LC 303, LC 560, LC 525).
  * *Tue:* 2D Matrix transformations & memory traversal order (LC 48, LC 54, LC 73).
  * *Wed:* Interval sorting & sweep-line basics (LC 56, LC 57, LC 435).
  * *Thu:* Trie node design and construction in C++ (LC 208).
  * *Fri:* Rabin-Karp rolling hash string search in Python (LC 28, LC 187).
* **Week 3 (Sat–Sun):**
  * *Sat:* Build a 2D Spatial Grid system in C++ with range query support. Solve LC 253, LC 218.
  * *Sun:* Refactor past week solutions for $O(1)$ auxiliary memory usage.

---

## Weeks 4–5: Linked Lists, Stacks, Queues & Monotonic Stacks

* **Week 4:** Singly/Doubly Linked Lists, Floyd's Cycle Detection, $K$-group node reversals, Min Stack, and building a thread-safe **LRU Cache** (LC 146) and **LFU Cache** (LC 460) in C++.
* **Week 5:** Monotonic Increasing/Decreasing Stacks, Monotonic Queues, Expression Calculators (LC 84, LC 85, LC 239, LC 224). Build a high-performance in-memory task queue in C++.

---

## Weeks 6–7: Binary Trees, BSTs & Heap Data Structures

* **Week 6:** Iterative & Recursive Tree Traversals, BFS level-order processing, Tree Depth properties, LCA algorithms, BST mutations (LC 98, LC 230, LC 236, LC 297).
* **Week 7:** Custom `MinHeap<T>` implementation from scratch, Top-$K$ elements pattern, Two-Heaps pattern for median tracking, K-Way Merging (LC 215, LC 295, LC 23). Build a real-time stock streaming analytics engine in Python.

---

## Weeks 8–9: Hash Tables, Prefix Sums & Binary Search

* **Week 8:** Open addressing vs. separate chaining, collision handling, custom hashing functions. Build a concurrent hash table in C++ with fine-grained bucket locking (`std::shared_mutex`).
* **Week 9:** Binary Search templates, rotated sorted arrays, Binary Search on Answer Space / Monotonic predicates ($isPossible(mid)$), Matrix binary search (LC 33, LC 875, LC 1011, LC 4).

---

## Weeks 10–11: Graph Fundamentals & Advanced Traversals

* **Week 10:** Adjacency List/Matrix graph representations, DFS/BFS grid patterns, Cycle detection, Disjoint Set Union (Union-Find with Path Compression and Union by Rank) in C++ (LC 200, LC 684, LC 1319).
* **Week 11:** Topological Sort (Kahn's Algorithm & DFS post-order), Dijkstra's Algorithm, Minimum Spanning Trees (Kruskal & Prim). Build an Autonomous Robot Pathfinding Engine (A* and Dijkstra) in C++.

---

## Week 12: Phase 1 Evaluation & MAANG-Style Mock Exam

* **Mon–Fri:** AddressSanitizer/Valgrind audit on all C++ builds, code cleanup, pattern cheat-sheet generation.
* **Sat:** 6-Hour MAANG Mock Exam (4 unseen problems in C++, 4 unseen problems in Python) under strict timed conditions.
* **Sun:** Detailed error analysis and Error Tracking Matrix logging.