# Chapter 8 — DSA-Ready Patterns and Complexity

**Time:** ~60 minutes  
**Goal:** Connect C++ syntax to the thinking style used in DSA problems.

This chapter is intentionally more about **how to think** than about new syntax.

---

## 1. Big-O: the practical version

Big-O describes how the amount of work grows as input size grows.

Common patterns:

| Complexity | Typical pattern |
|---|---|
| O(1) | direct access, a few arithmetic operations |
| O(log n) | binary-search style reduction |
| O(n) | one full scan |
| O(n log n) | efficient comparison sorting |
| O(n²) | pairwise comparison / nested full loops |
| O(2^n) | many naive recursive subset choices |

You do not need formal proofs yet. You need to recognize patterns.

---

## 2. Constant work

```cpp
int x = a[5];
```

This is O(1), assuming array/vector indexing.

The input can be huge, but the operation itself does not scale with `n`.

---

## 3. Linear scan

```cpp
for (int x : a) {
    if (x == target) return true;
}
```

Worst case: inspect every element.

Complexity: **O(n)**.

This is the basic pattern behind:

- finding an item
- counting items
- computing sum
- computing min/max
- checking a property

---

## 4. Nested loops

```cpp
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        // constant work
    }
}
```

Approximately `n * n` operations → **O(n²)**.

But do not blindly say “two loops means O(n²)”. For example:

```cpp
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
    }
}
```

This is O(10n) → **O(n)**.

The question is:

> How does the total work grow with n?

---

## 5. Two pointers

A common DSA pattern:

```cpp
int left = 0;
int right = static_cast<int>(a.size()) - 1;

while (left < right) {
    // use a[left] and a[right]
    ++left;
    --right;
}
```

Even though it uses a loop, each pointer moves only forward/inward.

Often this is **O(n)**.

Classic uses:

- reverse an array
- palindrome checks
- pair-sum in sorted arrays
- partitioning

---

## 6. Frequency counting

Suppose the problem asks:

> Does any number appear more than once?

A nested-loop solution is O(n²).

A hash-based solution can usually do it in average O(n):

```cpp
std::unordered_set<int> seen;

for (int x : a) {
    if (seen.count(x)) {
        return true;
    }
    seen.insert(x);
}
```

This is a classic example of trading space for speed.

---

## 7. Prefix sums

A prefix sum array stores cumulative totals.

Given:

```text
[3, 1, 4, 2]
```

prefix:

```text
[3, 4, 8, 10]
```

Code:

```cpp
std::vector<int> prefix(a.size());
prefix[0] = a[0];

for (int i = 1; i < static_cast<int>(a.size()); ++i) {
    prefix[i] = prefix[i - 1] + a[i];
}
```

Then a range sum can be answered quickly.

This is one of the first techniques that feels like “real DSA”.

---

## 8. Binary search intuition

Binary search repeatedly cuts a sorted search space roughly in half.

For a sorted array:

```text
low ---------------------- high
              ↓
             mid
```

After each comparison, discard roughly half the candidates.

That gives **O(log n)** time.

You do not need to implement every variant today. But you should understand the invariant:

> The remaining search interval contains the answer.

---

## 9. Invariants: a useful DSA habit

An invariant is something you deliberately keep true while an algorithm runs.

Example: two-pointer palindrome check.

Before each iteration:

```text
All characters already checked outside [left, right] match.
```

This way of thinking makes tricky algorithms much easier to reason about.

---

# Hands-On Practice

### 1. Linear search

Return index of target or `-1`.

### 2. Two-sum brute force

Find two indexes whose values sum to a target using O(n²).

### 3. Two-sum with a hash set/map

Improve it to average O(n).

### 4. Two-pointer palindrome

Check a string with two pointers.

### 5. Two-pointer pair sum

Given a sorted array, determine whether two values sum to target.

### 6. Prefix sum array

Build prefix sums.

### 7. Range sum queries

For a fixed array, answer many range-sum queries using prefix sums.

### 8. Maximum subarray — brute force

Find the maximum sum subarray by checking all start/end pairs.

Estimate its complexity.

### 9. Maximum subarray — Kadane's idea

Implement the linear-time version and compare the thinking with the brute-force solution.

### 10. Binary search

Implement iterative binary search for a sorted vector.

### 11. First occurrence

Modify binary search to find the first position of a target in a sorted array.

### 12. Complexity labeling

For each snippet below, write the tightest common Big-O you can.

Snippet A:

```cpp
for (int i = 0; i < n; ++i) {
    std::cout << a[i];
}
```

Snippet B:

```cpp
for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        // constant work
    }
}
```

Snippet C:

```cpp
while (n > 1) {
    n /= 2;
}
```

Snippet D:

```cpp
std::sort(a.begin(), a.end());
```

---

# DSA Problem-Solving Template

Before coding, write something like:

```text
Input:
Output:
Constraints:

Observation:

Brute force idea:

Can I improve it with:
- sorting?
- hashing?
- two pointers?
- prefix sums?
- stack/queue?
- binary search?

Target complexity:

Edge cases:
```

This is a habit worth developing now.

---

# Chapter Checkpoint

You should be able to look at a problem and at least consider:

- Can I solve this with one scan?
- Can sorting simplify it?
- Can a hash table remove a nested loop?
- Is this a two-pointer problem?
- Is there repeated range-sum work that suggests prefix sums?
- Is the input sorted, suggesting binary search?
- What is my time complexity?
- What extra space am I using?
