# Chapter 9 — Capstone Practice Set

**Time:** ~90 minutes  
**Goal:** Finish the refresher by solving realistic small problems without chapter-specific instructions.

These exercises intentionally mix concepts. This is where you check whether C++ feels natural again.

---

## How to use this chapter

For each problem:

1. Restate it in your own words.
2. Write an example.
3. Decide the data structure.
4. Write a simple algorithm.
5. Estimate time/space complexity.
6. Code it.
7. Test edge cases.

Do not immediately search for a pattern. Try first.

---

# Level 1 — Warm-up

## 1. Digit statistics

Given a positive integer, print:

- number of digits
- sum of digits
- largest digit
- smallest digit

Example:

```text
Input:  58321
Output:
Digits: 5
Sum: 19
Max: 8
Min: 1
```

---

## 2. Second largest distinct value

Given an integer vector, return the second largest **distinct** value.

Handle:

- duplicates
- fewer than two distinct values

Do not sort in your first solution.

---

## 3. Rotate array right by K

Example:

```text
[1 2 3 4 5], k = 2
-> [4 5 1 2 3]
```

First write a simple repeated-shift solution.

Then investigate a better solution using reversals.

---

# Level 2 — Hashing and strings

## 4. Anagram check

Determine whether two strings contain the same characters with the same frequencies.

Assume lowercase English letters first.

Try:

1. frequency array
2. sorting
3. `unordered_map`

Compare the approaches.

---

## 5. First non-repeating character

Given a string, return the index of its first unique character.

Example:

```text
"swiss" -> 1   // 'w'
```

Think about why one pass may not be enough with only a simple count table.

---

## 6. Longest run of the same character

Example:

```text
"aaabbccccdaa" -> 4
```

Return the length of the longest consecutive run.

---

# Level 3 — Arrays and patterns

## 7. Move zeros to the end

Move all zero values to the end while preserving the relative order of non-zero values.

Try to achieve O(n) time and O(1) extra space.

---

## 8. Missing number

You are given `n` distinct numbers from `0` through `n`. Exactly one is missing.

Example:

```text
[3, 0, 1] -> 2
```

Try:

1. sorting
2. arithmetic sum
3. XOR

Understand the trade-offs rather than blindly memorizing the XOR trick.

---

## 9. Majority element

Find an element that appears more than `n/2` times, assuming one always exists.

First solve using a frequency map.

Then, as a stretch exercise, learn the Boyer–Moore voting idea.

---

## 10. Merge intervals — simple version

Given intervals such as:

```text
[1,3]
[2,6]
[8,10]
[9,12]
```

merge overlapping intervals.

Expected shape:

```text
[1,6]
[8,12]
```

This is a great practice problem because sorting + linear scanning is a classic DSA pattern.

---

# Level 4 — Stack and queue

## 11. Valid parentheses

Return true if a string of brackets is properly nested.

Examples:

```text
"()[]{}"   -> true
"([{}])"   -> true
"([)]"     -> false
```

Use a stack.

---

## 12. Next greater element — brute force

For every element, find the first greater element to its right.

Example:

```text
[2, 1, 2, 4, 3]
-> [4, 2, 4, -1, -1]
```

First solve with O(n²).

Then treat it as a preview of the monotonic-stack pattern and attempt O(n).

---

## 13. Queue using two stacks — optional stretch

Implement a FIFO queue using two `std::stack<int>` objects.

Focus on understanding the data movement rather than writing the shortest code.

---

# Level 5 — DSA bridge problems

## 14. Binary search variations

Given a sorted vector:

1. find target
2. find first occurrence
3. find last occurrence
4. count occurrences

The last three should reuse the binary-search idea rather than repeatedly scanning.

---

## 15. Prefix sum queries

Read an array and Q range queries.

Each query asks for the sum from `L` to `R`.

Process all queries efficiently using a prefix-sum array.

---

## 16. Top K frequent values

Given an array and K, return the K most frequent values.

Start with a frequency map plus sorting.

Stretch: use a priority queue.

---

# Final Capstone — Mini DSA Console Program

Build a menu-driven program around a vector of integers.

Support:

```text
1. Add value
2. Remove last value
3. Print values
4. Find minimum
5. Find maximum
6. Search for value
7. Sort ascending
8. Reverse
9. Count frequency of a value
10. Print unique values
11. Show sum and average
0. Exit
```

Requirements:

- Put each major operation in a function.
- Use `std::vector`.
- Handle an empty vector safely.
- Use STL algorithms where they make the code clearer.
- Keep `main()` small.

After it works, add:

- second largest distinct value
- rotate by K
- prefix sums
- binary search after sorting

This single project revises a surprisingly large percentage of the material in this course.

---

# Final Self-Test

Without opening earlier chapters, write code for these from scratch:

### Syntax

- input two integers
- print a formatted result
- write a function with a reference parameter

### Control flow

- prime check
- digit sum
- nested loop

### Sequences

- vector traversal
- reverse in place
- maximum
- frequency count

### STL

- sort a vector
- use a set
- use an unordered map
- use a stack
- use a queue
- use a priority queue

### DSA patterns

- two pointers
- prefix sum
- binary search
- hash-based lookup

If you can implement most of these without looking at notes, you are in a strong position to start formal DSA training.

---

# What to learn next

After this refresher, a sensible DSA progression is:

```text
Arrays + Strings
    ↓
Hashing
    ↓
Two pointers / Sliding window
    ↓
Stack + Queue
    ↓
Binary search
    ↓
Linked lists
    ↓
Trees + BST
    ↓
Heaps / Priority queues
    ↓
Graphs
    ↓
Recursion + Backtracking
    ↓
Greedy
    ↓
Dynamic Programming
```

Do not worry about finishing this entire sequence quickly. The main goal of this refresher is to remove C++ friction so that future DSA learning can focus on **algorithms and problem solving** instead of syntax.

---

# One final habit

When a DSA problem feels difficult, do not immediately think:

> “Which trick do I remember?”

Instead ask:

> “What information do I need to maintain as I scan the input?”

That question naturally leads you toward arrays, hash tables, two pointers, stacks, queues, heaps, and other data structures.
