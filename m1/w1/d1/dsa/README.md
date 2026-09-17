## Day 1 DSA: Arrays, traversal, and Big-O

Today’s goal is not to memorize many tricks. It is to learn how to look at an array problem and immediately ask:

1. What is the input?
2. Do I need to inspect every element?
3. What information must I remember while scanning?
4. Can I solve it in one pass?
5. What are the time and space complexities?

## 1. What is an array?

An array stores values in contiguous positions, accessed by an index.

```text
Index:  0   1   2   3   4
Value:  8  12   3  19   5
```

Important operations:

| Operation | Typical complexity | Reason |
|---|---:|---|
| Access `arr[i]` | O(1) | Direct index access |
| Update `arr[i]` | O(1) | Direct index access |
| Traverse all values | O(n) | Must visit each element |
| Search an unsorted array | O(n) | May need to inspect every element |
| Insert/delete at end of `vector` | O(1) amortized | Usually adds at the end |
| Insert/delete in the middle | O(n) | Remaining values may shift |

In C++ interview problems, use `std::vector<int>` most of the time. Think of it as a flexible array.

## 2. Array traversal

Traversal means visiting every element, usually once.

```cpp
for (int number : numbers) {
    // process number
}
```

or:

```cpp
for (int index = 0; index < numbers.size(); ++index) {
    // use numbers[index]
}
```

Use the first when you only need the value. Use the second when you need the index or must modify elements.

## 3. The one-pass pattern

Many easy array problems use this model:

```text
1. Initialize an answer.
2. Visit each element once.
3. Update the answer if needed.
4. Return or print the answer.
```

Example: finding the largest number.

```text
Numbers: [8, 12, 3, 19, 5]

Start:
largest = 8

Read 12 → 12 is larger → largest = 12
Read 3  → no change
Read 19 → 19 is larger → largest = 19
Read 5  → no change

Answer: 19
```

Complexity:

```text
Time: O(n)     // inspect all n numbers
Space: O(1)    // only store one extra variable
```

## 4. Brute force vs efficient thinking

Before writing code, consider the simplest correct approach.

For “find the largest number,” there is no need to compare every pair of numbers. A single scan works.

For “does the array contain a duplicate?”:

- Brute force: compare every pair → O(n²).
- Better approach: maintain a hash set of seen values → O(n) average time, O(n) extra space.

You do not need to master hash maps today. Just recognize the idea:

> If I need to remember whether I have seen something before, a hash set or hash map may help.

## 5. Edge cases to check

For every array problem, ask:

- Is the array empty?
- Does it contain one element?
- Can values be negative?
- Can values repeat?
- Is the result guaranteed to exist?
- Could addition overflow an `int`?
- Must I return an index, a value, or a boolean?

Example: for largest number, an initial value of `0` fails for `[-8, -3, -12]`. Initialize from the first element instead, assuming the array is non-empty.

## Notes to copy

```md
# Day 1 DSA — Arrays and Big-O

## Array facts

- An array stores ordered values.
- Each value has an index starting at 0.
- Direct index access is O(1).
- Visiting every element is O(n).
- Searching an unsorted array is O(n).

## One-pass pattern

1. Initialize the answer.
2. Traverse every element.
3. Update the answer.
4. Return the answer.

## Complexity

- One loop through n values: O(n)
- Two independent loops: O(n) + O(n) = O(n)
- Nested loops: usually O(n²)
- Extra variables only: O(1) space
- Hash set/map storing n values: O(n) space

## Edge-case checklist

- Empty array?
- One element?
- Negative values?
- Duplicates?
- Overflow?
- Return value, index, or boolean?

## Interview explanation template

“I will scan the array once and maintain ______.
For each value, I will ______.
This visits every element once, so time complexity is O(n).
I use only ______ extra variables, so space complexity is O(1).”
```

## Practice problems

Do these in order. Do not look for solutions before you can explain the approach aloud.

### Core 1: Find the largest element

Given an integer array, return its largest value.

```text
Input:  [8, 12, 3, 19, 5]
Output: 19
```

Expected approach:

- Start with the first element as the current maximum.
- Scan the remaining values.
- Replace the maximum when a larger value appears.

Target complexity: **O(n) time, O(1) space**.

### Core 2: Count even numbers

Given an integer array, return how many values are even.

```text
Input:  [4, 7, 0, -2, 11, 18]
Output: 4
```

Expected approach:

- Traverse once.
- Use `number % 2 == 0`.
- Increment a counter.

Target complexity: **O(n) time, O(1) space**.

### Practice 3: Find the first occurrence

Given an array and a target, return the first index where the target occurs. Return `-1` if absent.

```text
Input:  numbers = [5, 8, 2, 8, 9], target = 8
Output: 1
```

Target complexity: **O(n) time, O(1) space**.

### Practice 4: Calculate the running sum

For each index, return the sum of values from index `0` through that index.

```text
Input:  [1, 2, 3, 4]
Output: [1, 3, 6, 10]
```

Hint: maintain one variable called `runningSum`.

Target complexity: **O(n) time, O(n) output space**.

### Stretch: Contains duplicate

Return `true` if any number appears more than once.

```text
Input:  [1, 2, 3, 1]
Output: true
```

First think of the brute-force approach. Then consider what information you would need to remember while scanning.

## Before you start coding

For Core 1, answer these aloud:

- Why must every algorithm inspect all values in the worst case?
- Why should the initial maximum be the first array value rather than `0`?
- What should happen if the input is empty?
- Why is the solution O(n), not O(1)?
