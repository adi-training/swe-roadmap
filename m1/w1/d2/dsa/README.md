# Day 2 DSA — Array Traversal, Accumulators, and Two Pointers

Day 1 was about scanning an array and remembering one answer, such as the largest value.

Day 2 extends that idea:

1. Track a running value: sum, count, min, max.
2. Modify an array in place.
3. Use two indexes when reading and writing happen at different positions.

## 1. The accumulator pattern

An accumulator is a variable that stores a result while you traverse an array.

Common accumulators:

| Task | Accumulator |
|---|---|
| Find sum | `sum` |
| Count even values | `count` |
| Find largest value | `largest` |
| Find smallest value | `smallest` |
| Build a result | `result` vector |

Example: sum values.

```text
Input: [4, 7, 1, 9]

sum = 0

Read 4 → sum = 4
Read 7 → sum = 11
Read 1 → sum = 12
Read 9 → sum = 21
```

Complexity:

```text
Time: O(n)
Space: O(1)
```

## 2. Minimum and maximum in one pass

You can calculate both values in one loop.

```text
Input: [8, -2, 15, 4, 0]

minimum = 8
maximum = 8

Read -2 → minimum = -2
Read 15 → maximum = 15
Read 4  → no change
Read 0  → no change
```

Key rule:

> Initialize `minimum` and `maximum` with the first array value, not with `0`.

Why? Because an all-negative input would fail otherwise.

```text
Input: [-8, -3, -12]

Incorrect initialization:
maximum = 0

Incorrect output: 0
Correct output: -3
```

## 3. In-place modification

Sometimes an interviewer wants you to change the original array rather than create a new one.

Example:

```text
Input:  [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
```

You could create another vector, but that requires O(n) extra space.

A better approach modifies the original vector:

```text
Time: O(n)
Extra space: O(1)
```

## 4. Two-pointer pattern

A pointer is simply an index.

For Move Zeroes, use:

- `readIndex`: checks every element.
- `writeIndex`: points to where the next non-zero value belongs.

Walkthrough:

```text
Input: [0, 1, 0, 3, 12]

writeIndex = 0

readIndex = 0 → value is 0 → do nothing
readIndex = 1 → value is 1 → swap with position 0
Array: [1, 0, 0, 3, 12]
writeIndex = 1

readIndex = 2 → value is 0 → do nothing
readIndex = 3 → value is 3 → swap with position 1
Array: [1, 3, 0, 0, 12]
writeIndex = 2

readIndex = 4 → value is 12 → swap with position 2
Array: [1, 3, 12, 0, 0]
writeIndex = 3
```

Important invariant:

> Before `writeIndex`, all values are non-zero and in their original relative order.

## Notes to copy

```md
# Day 2 DSA — Arrays

## Accumulator pattern

Use one variable to store a result while scanning an array.

Examples:
- sum
- count
- minimum
- maximum

General structure:

1. Initialize accumulator.
2. Traverse the array once.
3. Update accumulator.
4. Return answer.

## Initialization rule

For min/max:
- Initialize using the first array element.
- Do not initialize with 0 because input may contain only negative values.

## Two pointers

Use two indexes when:
- Reading and writing happen at different positions.
- Moving/removing/filtering values in-place.
- Comparing values from two ends or two locations.

Move Zeroes:
- readIndex examines every value.
- writeIndex marks where next non-zero value goes.

## Complexity

One traversal:
- Time: O(n)

Only a few variables:
- Extra space: O(1)

New result vector:
- Extra space: O(n)
```

# Core problem 1 — Calculate sum and average

## Problem

```text
Input:  [4, 7, 1, 9]
Output:
Sum: 21
Average: 5.25
```

## Think before coding

- What if the vector is empty?
- Why should the sum be calculated before the average?
- What happens if you divide two integers in C++?

Important:

```cpp
21 / 4
```

produces:

```text
5
```

not:

```text
5.25
```

Use `static_cast<double>` to perform decimal division.

## Pseudocode

```text
If array is empty:
    return 0.0 or report invalid input

sum = 0

For every number:
    add number to sum

average = sum / number of elements

Return average
```

## Reference solution

```cpp
#include <vector>

int calculateSum(const std::vector<int>& numbers) {
    int sum = 0;

    for (int number : numbers) {
        sum += number;
    }

    return sum;
}

double calculateAverage(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return 0.0;
    }

    int sum = calculateSum(numbers);

    return static_cast<double>(sum) / numbers.size();
}
```

Interview explanation:

> I traverse the vector once and maintain a running sum. I divide the final sum by the number of elements, converting to `double` to avoid integer division. The algorithm takes O(n) time and O(1) extra space.

# Core problem 2 — Move Zeroes

## Problem

```text
Input:  [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
```

## Constraints to respect

- Preserve the relative order of non-zero values.
- Modify the original vector.
- Avoid creating a second vector.

## Pseudocode

```text
writeIndex = 0

For readIndex from 0 to end:
    If current number is not zero:
        swap number at writeIndex with number at readIndex
        increase writeIndex
```

## Reference solution

```cpp
#include <utility>
#include <vector>

void moveZeroes(std::vector<int>& numbers) {
    int writeIndex = 0;

    for (int readIndex = 0;
         readIndex < static_cast<int>(numbers.size());
         ++readIndex) {
        if (numbers[readIndex] != 0) {
            std::swap(numbers[writeIndex], numbers[readIndex]);
            ++writeIndex;
        }
    }
}
```

Interview explanation:

> I use a read pointer to inspect each number and a write pointer to track where the next non-zero number belongs. Whenever I find a non-zero value, I swap it into the write position. This processes each element once, so it is O(n) time and O(1) extra space.

# Practice problems

Complete these without looking at the reference solutions.

## Practice 1 — Count positive, negative, and zero values

```text
Input:  [-3, 0, 4, -1, 0, 8]
Output:
Positive: 2
Negative: 2
Zero: 2
```

Target:

```text
Time: O(n)
Space: O(1)
```

## Practice 2 — Find minimum and maximum

```text
Input:  [8, -2, 15, 4, 0]
Output:
Minimum: -2
Maximum: 15
```

Target:

```text
Time: O(n)
Space: O(1)
```

## Practice 3 — Double values in place

```text
Input:  [1, 3, 5]
Output: [2, 6, 10]
```

Requirement: modify the original vector.

Target:

```text
Time: O(n)
Space: O(1)
```

## Practice 4 — Remove a target value in place

Given an array and a target value, move every non-target value to the beginning and return the new logical length.

```text
Input:  numbers = [3, 2, 2, 3], target = 3
Output: newLength = 2
Updated beginning of vector: [2, 2]
```

Hint: use `readIndex` and `writeIndex`, but copy non-target values instead of swapping.

# Day 2 interview questions

### Why is `std::vector` commonly used in C++ interviews?

It behaves like a dynamic array, supports fast indexed access, automatically manages memory, and provides useful operations such as `push_back()` and `size()`.

### Why does Move Zeroes use O(1) extra space?

It changes values inside the original vector and only uses a few integer index variables. It does not create another array that grows with the input.

### Why is the two-pointer Move Zeroes solution O(n)?

The read pointer advances through the array once. Although swaps may occur, each position is processed a constant number of times.

### Why must an average calculation use `static_cast<double>`?

When both operands are integers, C++ performs integer division and discards the decimal part. Converting one operand to `double` produces a decimal result.

### What is an invariant?

An invariant is a condition that remains true during an algorithm. In Move Zeroes, every position before `writeIndex` always contains a non-zero value in its correct order.