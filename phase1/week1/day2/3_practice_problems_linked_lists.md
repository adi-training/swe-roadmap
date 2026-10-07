# Practice Problem Set: Linked Lists & Memory Node Management

## Tier 1: Foundational Mechanics & Pointer Operations

### Problem 1: In-Place Singly Linked List Reversal (Recursive)
Write a recursive function `ListNode* reverseRecursive(ListNode* head)` that reverses a singly linked list in $O(N)$ time.

### Problem 2: Palindrome Linked List Verification
Write a function `bool isPalindrome(ListNode* head)` that checks whether a singly linked list reads the same forward and backward in $O(N)$ time and $O(1)$ auxiliary space.

### Problem 3: Detect Cycle Node Entry Point (Floyd's Algorithm II)
Given a linked list that contains a cycle, return the exact `ListNode*` where the cycle begins. Prove mathematically why fast and slow pointer convergence works.

---

## Tier 2: Algorithmic Manipulation & Intersecting Lists

### Problem 4: Intersection of Two Linked Lists
Given two singly linked lists `headA` and `headB`, find the node at which the two lists intersect in $O(N + M)$ time and $O(1)$ extra space.

### Problem 5: Swap Nodes in Pairs
Given a singly linked list, swap every two adjacent nodes and return its head in-place ($O(1)$ space).

### Problem 6: Add Two Numbers Represented by Linked Lists
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order. Add the two numbers and return the sum as a linked list.

---

## Tier 3: Advanced Systems Architecture & Cache Design

### Problem 7: Design LRU Cache (Least Recently Used)
Design a data structure that follows the constraints of a Least Recently Used (LRU) Cache in $O(1)$ average time for both `get` and `put` operations using a Hash Map + Doubly Linked List.

### Problem 8: Flatten a Multilevel Doubly Linked List
You are given a doubly linked list, where in addition to the next and previous pointers, each node has a child pointer, which may point to a separate doubly linked list. Flatten the list so all nodes appear in a single-level doubly linked list.

### Problem 9: Clone List with Random Pointer
A linked list of length $N$ is given such that each node contains an additional random pointer, which could point to any node in the list or null. Construct a deep copy of the list in $O(N)$ time and $O(1)$ auxiliary space (excluding new nodes).

### Problem 10: Cache Line Locality vs Pointer Chasing Benchmark
Write a C++ benchmark program comparing total iteration runtime across $10^7$ elements between a `std::vector<int>` and `CustomLinkedList<int>`. Explain the hardware CPU L1/L2/L3 cache miss rationale.