# Chapter 4 — Lists, Tuples, Dictionaries and Sets

**Time:** ~75 minutes  
**Goal:** Become fluent with the four everyday container types that dominate practical Python and DSA.

---

## 1. Lists

```python
nums = [10, 20, 30]
nums.append(40)
nums[1] = 99
```

Useful operations:

```python
len(nums)
nums.append(x)
nums.pop()
nums.insert(i, x)
nums.remove(x)
nums.sort()
```

Indexing and slicing:

```python
nums[0]
nums[-1]
nums[1:4]
nums[::-1]
```

## 2. Tuples

Tuples are immutable sequences.

```python
point = (10, 20)
x, y = point
```

They are useful for fixed records and returning multiple values.

## 3. Dictionaries

A dictionary maps keys to values.

```python
student = {"name": "Maya", "score": 92}
print(student["score"])
```

A powerful DSA pattern:

```python
freq = {}
for x in nums:
    freq[x] = freq.get(x, 0) + 1
```

## 4. Sets

A set stores unique elements and gives fast average-case membership checks.

```python
seen = set()
seen.add(10)
print(10 in seen)
```

Common operations:

```python
a | b   # union
a & b   # intersection
a - b   # difference
```

## 5. Choosing the right container

| Need | Use |
|---|---|
| ordered mutable sequence | `list` |
| fixed/immutable grouping | `tuple` |
| key → value lookup | `dict` |
| unique items / membership | `set` |

---

# Hands-on Exercises

## E1. Sum a list

Read a list of integers and print the sum using a loop.

## E2. Find maximum

Find the largest value without `max()`.

## E3. Reverse a list

Reverse a list without calling `.reverse()`.

## E4. Remove duplicates

Given a list, produce a list containing each value once while preserving first appearance order.

## E5. Frequency map

Build a dictionary of element frequencies.

## E6. Most frequent value

Return the value with the highest frequency. In a tie, returning any one is acceptable.

## E7. Two-sum

Given a list and target, print two indices whose values add to target using a dictionary.

## E8. Common elements

Given two lists, print their unique common elements.

## E9. Anagram check

Return whether two strings are anagrams using a frequency dictionary.

## E10. Group words by first letter

Given a list of words, build a dictionary mapping each first letter to the words beginning with it.

## E11. Stack

Implement push, pop, and peek using a Python list.

## E12. Queue

Implement a simple queue using `collections.deque`.

