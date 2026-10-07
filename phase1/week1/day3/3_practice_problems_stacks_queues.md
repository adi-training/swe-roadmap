# Practice Problem Set: Stacks, Queues & Monotonic Structures

## Tier 1: Foundational Mechanics & Adaptor Structures

### Problem 1: Implement Queue using Stacks
Design a FIFO Queue using two LIFO Stacks (`std::stack`). Implement `push`, `pop`, `peek`, and `empty` such that amortized time complexity per operation is $O(1)$.

### Problem 2: Next Greater Element I
Given two arrays `nums1` and `nums2` where `nums1` is a subset of `nums2`, find the next greater element for each value of `nums1` in `nums2` using a Monotonic Stack in $O(N)$ time.

### Problem 3: Daily Temperatures
Given an array of integers `temperatures` representing daily temperatures, return an array `answer` such that `answer[i]` is the number of days you have to wait after the $i^{\text{th}}$ day to get a warmer temperature ($O(N)$ time).

---

## Tier 2: Monotonic Processing & Boundary Search

### Problem 4: Largest Rectangle in Histogram
Given an array of integers `heights` representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram in $O(N)$ time.

### Problem 5: Trapping Rain Water (Stack Approach)
Given $N$ non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining using a monotonic stack in $O(N)$ time.

### Problem 6: Simplify Path (Unix-Style File System)
Given an absolute Unix file system path, simplify it using a stack data structure to evaluate `.`, `..`, and multiple slashes `//`.

---

## Tier 3: High-Performance Architecture & Lock-Free Design

### Problem 7: Design Circular Deque (LeetCode 641)
Design your implementation of the circular double-ended queue (deque) without using standard build-in libraries.

### Problem 8: Maximum Frequency Stack (FreqStack)
Design a stack-like data structure to push elements and pop the most frequent element. If there is a tie for the most frequent element, the element closest to the top of the stack is popped.

### Problem 9: Monotonic Queue Invariant Mathematical Proof
Prove by induction that inserting $N$ elements into a Monotonic Queue maintains both $O(N)$ total execution runtime and non-increasing/non-decreasing invariant sorting order.

### Problem 10: Single-Producer Single-Consumer (SPSC) Lock-Free Ring Buffer Design
Outline the design and atomic memory ordering constraints (`std::atomic<size_t>` with `memory_order_acquire` / `memory_order_release`) for a thread-safe lock-free ring buffer queue.