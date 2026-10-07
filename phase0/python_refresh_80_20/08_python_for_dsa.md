# Chapter 8 — Python Patterns You Will Use in DSA

**Time:** ~75 minutes  
**Goal:** Turn Python knowledge into practical DSA building blocks.

---

## 1. Complexity mindset

You should start asking:

- How many times does this loop run?
- Am I repeatedly scanning the same data?
- Can a set/dictionary replace a nested loop?
- Am I sorting when I do not need to?

Typical patterns:

| Pattern | Approximate cost |
|---|---:|
| direct list index | O(1) |
| dictionary/set membership | O(1) average |
| scan | O(n) |
| sorting | O(n log n) |
| nested full scans | O(n²) |

## 2. Frequency counting

```python
freq = {}
for x in nums:
    freq[x] = freq.get(x, 0) + 1
```

Or, when appropriate:

```python
from collections import Counter
freq = Counter(nums)
```

## 3. Two-sum with a hash map

```python
def two_sum(nums, target):
    seen = {}
    for i, x in enumerate(nums):
        need = target - x
        if need in seen:
            return seen[need], i
        seen[x] = i
    return None
```

## 4. Stack

A Python list is excellent for stack operations at the end:

```python
stack = []
stack.append(x)
stack.pop()
stack[-1]
```

## 5. Queue

Use `deque`, not `list.pop(0)`:

```python
from collections import deque
q = deque()
q.append(x)
q.popleft()
```

## 6. Binary search

Use `bisect` when the data is sorted and the problem fits the standard library's behavior:

```python
from bisect import bisect_left
idx = bisect_left(nums, target)
```

You should still understand the manual binary-search pattern.

## 7. Prefix sums

```python
prefix = [0]
for x in nums:
    prefix.append(prefix[-1] + x)
```

Then sum of `nums[l:r+1]` is:

```python
prefix[r + 1] - prefix[l]
```

## 8. Two pointers

Typical example:

```python
left, right = 0, len(nums) - 1
while left < right:
    total = nums[left] + nums[right]
    if total == target:
        break
    if total < target:
        left += 1
    else:
        right -= 1
```

The important idea is that each pointer usually moves only forward, so the loop can be O(n).

---

# Hands-on Exercises

## E1. First duplicate

Return the first value encountered twice while scanning left-to-right.

## E2. Two-sum indices

Return indices of two numbers adding to target in O(n) average time.

## E3. Valid parentheses

Use a stack to determine whether `()[]{}` brackets are balanced and correctly nested.

## E4. Top-level frequency

Return the value that appears most frequently.

## E5. Prefix-sum range queries

Precompute prefix sums and answer multiple `[l, r]` sum queries.

## E6. Binary search

Implement iterative binary search returning the index of target or `-1`.

## E7. First occurrence

In a sorted list with duplicates, return the first index of a target.

## E8. Two-pointer pair

Given a sorted list, find whether any pair sums to target.

## E9. Move zeros

Move all zeros to the end of a list in-place while preserving the relative order of non-zero values.

## E10. Sliding-window maximum sum

Given positive numbers and window size `k`, return the largest sum of any contiguous subarray of size `k`.

## E11. Queue with two stacks

Implement a queue using two lists as stacks.

## E12. BFS level order idea

Given an adjacency list of an unweighted graph, write BFS from a start node and return the visitation order.

