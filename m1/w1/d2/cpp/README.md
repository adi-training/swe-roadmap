These Day 2 C++ programs practice vectors, references, `const`, and file handling. Do the first five as core work; the rest are stretch.

| # | Program | Skills practiced | Expected example outcome |
|---:|---|---|---|
| 1 | Vector printer | `std::vector`, range-based loops | Input vector `{4, 7, 1}` → Output: `[4, 7, 1]` |
| 2 | Sum and average | `const std::vector<int>&`, traversal, `double` conversion | `{4, 7, 1, 9}` → `Sum: 21`, `Average: 5.25` |
| 3 | Minimum and maximum | One-pass traversal, edge cases | `{-8, 4, 15, 0}` → `Min: -8`, `Max: 15` |
| 4 | Append value by reference | Pass-by-reference, `push_back()` | Vector `{1, 2}`, add `3` → `{1, 2, 3}` |
| 5 | Scale values by reference | Modifying a vector in-place | `{2, 4, 6}`, factor `3` → `{6, 12, 18}` |
| 6 | Count words in a file | `std::ifstream`, `std::string`, file-open check | File: `hello world\nC++ is fun` → `Word count: 5` |
| 7 | File preview | `std::getline`, vector of strings | Print the first three lines of a log file |
| 8 | Log-level counter | String search and maps/vectors | Log with `INFO`, `WARNING`, `ERROR` lines → `INFO: 2, WARNING: 1, ERROR: 1` |

## Core Program 1 — Vector printer

Create:

```text
01_vector_printer.cpp
```

Requirements:

- Declare a vector of integers.
- Write a function named `printVector`.
- Accept the vector as `const std::vector<int>&`.
- Print values in this format:

```text
[4, 7, 1, 9]
```

Expected learning outcome:

> I can traverse a vector without copying it.

## Core Program 2 — Sum and average

Create:

```text
02_sum_average.cpp
```

Requirements:

- Write `calculateSum`.
- Write `calculateAverage`.
- Handle an empty vector safely.

Example:

```text
Input:  [4, 7, 1, 9]
Output:
Sum: 21
Average: 5.25
```

Expected learning outcome:

> I can use a constant reference for read-only vector functions and avoid integer-division mistakes.

## Core Program 3 — Minimum and maximum

Create:

```text
03_min_max.cpp
```

Requirements:

- Write `findMinimum`.
- Write `findMaximum`.
- Handle negative numbers correctly.
- Decide what happens for an empty vector.

Example:

```text
Input:  [-8, 4, 15, 0]
Output:
Minimum: -8
Maximum: 15
```

Expected learning outcome:

> I can apply the one-pass accumulator pattern to multiple values.

## Core Program 4 — Append by reference

Create:

```text
04_append_value.cpp
```

Requirements:

- Write a function:

```cpp
void appendValue(std::vector<int>& values, int value);
```

- Print the vector before and after calling the function.

Example:

```text
Before: [1, 2]
After:  [1, 2, 3]
```

Expected learning outcome:

> I understand that `std::vector<int>&` lets a function modify the caller’s original vector.

## Core Program 5 — Scale values in place

Create:

```text
05_scale_values.cpp
```

Requirements:

- Write a function that multiplies every vector value by a supplied factor.
- Modify the same vector; do not create a second output vector.

Example:

```text
Input:  [2, 4, 6]
Factor: 3
Output: [6, 12, 18]
```

Expected learning outcome:

> I can use an index loop or reference loop to update vector values in place.

## Stretch Program 6 — Word counter

Create:

```text
06_word_counter.cpp
```

Requirements:

- Take a file path as a command-line argument.
- Open the file with `std::ifstream`.
- Print a helpful error if opening fails.
- Count words in the file.

Example file:

```text
hello world
C++ is fun
```

Expected output:

```text
Words: 5
```

Expected learning outcome:

> I can open a file safely and process its content with a loop.

## Stretch Program 7 — File preview tool

Create:

```text
07_file_preview.cpp
```

Requirements:

- Receive a file path through `argv`.
- Count all file lines.
- Store and print only the first three lines.
- Handle an empty or missing file.

Example output:

```text
Total lines: 5
Preview:
1. 2026-09-20 INFO Sensor started
2. 2026-09-20 INFO Reading received
3. 2026-09-20 WARNING Battery low
```

## Stretch Program 8 — Log-level counter

Create:

```text
08_log_level_counter.cpp
```

Requirements:

- Read a log file line by line.
- Count lines containing `INFO`, `WARNING`, and `ERROR`.
- Print the totals.

Example input:

```text
INFO Sensor started
WARNING Battery low
INFO Reading received
ERROR Connection lost
```

Expected output:

```text
INFO: 2
WARNING: 1
ERROR: 1
```

This is an excellent bridge into your Sensor Log Analyzer project.