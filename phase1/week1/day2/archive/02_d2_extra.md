# Day 2 Extra — Vector Details, File-Path Debugging, and Optional Practice

This is optional support for `DAY_02_README.md`. Complete the main Day 2 guide first.

---

# 1. Clarifying the Day 2 C++ code

## 1.1 What is `std::size_t`?

`std::size_t` is the type C++ uses for sizes and indexes.

```cpp
std::size_t index = 0;
std::size_t numberOfValues = numbers.size();
```

Why use it?

```text
numbers.size() returns std::size_t.
Using the same type avoids warnings about comparing different integer types.
```

For now, use this pattern when you need an index:

```cpp
for (std::size_t index = 0; index < numbers.size(); ++index) {
    std::cout << numbers[index] << '\n';
}
```

## 1.2 What does `int& number` mean in a loop?

Compare these two loops:

```cpp
for (int number : numbers) {
    number *= 2;
}
```

This changes a temporary copy. The vector remains unchanged.

```cpp
for (int& number : numbers) {
    number *= 2;
}
```

This changes the original values inside the vector.

Example:

```text
Before: [2, 4, 6]
After value-copy loop: [2, 4, 6]
After reference loop:  [4, 8, 12]
```

Use `const int& number` only for larger objects. For small integers, `int number` is simple and efficient when you only need to read it.

## 1.3 Why does the file program use `while`?

The number of lines in a file is not known in advance.

```cpp
while (std::getline(inputFile, line)) {
    // This runs only after a line was successfully read.
}
```

The loop automatically stops after the final line. This is safer than guessing how many lines a file has.

## 1.4 Relative paths versus absolute paths

This is a relative path:

```bash
data/sample.log
```

It means:

> “Look for `data/sample.log` inside the folder where I am currently running the command.”

Check your current folder:

```bash
pwd
```

For the project command below to work:

```bash
./build/log_analyzer data/sample.log
```

`pwd` should print:

```text
/home/guru/Documents/ChatGPT/Roadmap2028/cpp-log-analyzer
```

An absolute path works from any folder:

```bash
./build/log_analyzer /home/guru/Documents/ChatGPT/Roadmap2028/cpp-log-analyzer/data/sample.log
```

---

# 2. Common Day 2 errors and fixes

| Symptom | Likely cause | What to do |
|---|---|---|
| `vector was not declared` | Missing vector header | Add `#include <vector>` |
| `ifstream has incomplete type` | Missing file-stream header | Add `#include <fstream>` |
| `No such file or directory` | Running from the wrong folder or typo in path | Run `pwd`, then `ls data` |
| `Permission denied` while running | Executable is missing or not executable | Rebuild using `cmake --build build` |
| CMake says source does not exist | Command was run outside project folder | `cd` into `cpp-log-analyzer` first |
| Expected decimal but got whole number | Integer division | Use `static_cast<double>(sum)` |
| Vector did not change after a function call | Function received a copy | Use `std::vector<int>&` when modification is intended |

Useful diagnosis commands:

```bash
pwd
ls
ls data
ls build
git status
```

---

# 3. Optional C++ practice programs

## Practice A — Find minimum and maximum

### Goal

Practice scanning a vector and maintaining two answers.

```text
Input:  [8, -2, 15, 4, 0]
Output:
Minimum: -2
Maximum: 15
```

### Rules

1. Reject or handle empty input.
2. Initialize both values from the first vector element.
3. Scan the rest of the vector once.

Expected complexity:

```text
Time: O(n)
Extra space: O(1)
```

## Practice B — Append values through a reference

### Goal

Practice a function that modifies a caller’s vector.

Create a function with this signature:

```cpp
void appendValue(std::vector<int>& numbers, int value);
```

Example:

```text
Before: [1, 2]
Value:  3
After:  [1, 2, 3]
```

Question to answer aloud:

> Why must the vector parameter include `&`?

Answer: Without `&`, the function receives a copy and the caller’s original vector will not change.

## Practice C — File word counter

### Goal

Read a file and count words rather than lines.

Example file contents:

```text
hello world
C++ is fun
```

Expected output:

```text
Word count: 5
```

Hint:

```cpp
std::string word;

while (inputFile >> word) {
    // A word was read successfully.
}
```

This differs from `std::getline`, which reads complete lines.

## Practice D — Move Zeroes dry run

Before writing code, complete this table for the input `[0, 1, 0, 3, 12]`.

| `readIndex` | Current value | `writeIndex` before | Array after action | `writeIndex` after |
|---:|---:|---:|---|---:|
| 0 | 0 | 0 | | |
| 1 | 1 | 0 | | |
| 2 | 0 | 1 | | |
| 3 | 3 | 1 | | |
| 4 | 12 | 2 | | |

Correct final array:

```text
[1, 3, 12, 0, 0]
```

---

# 4. Day 2 interview rehearsal

Practice answering these in 30–45 seconds each.

## Why pass a vector as `const std::vector<int>&`?

It avoids copying a potentially large vector and guarantees that the function will not modify the original data.

## What is the difference between `std::getline` and `inputFile >> word`?

`std::getline` reads an entire line, including spaces within the line. `inputFile >> word` reads one whitespace-separated word at a time.

## Why check whether an input file opened successfully?

A supplied file may not exist or may be inaccessible. Checking immediately lets the program report a useful error and stop safely.

## What is the complexity of calculating a vector’s sum?

O(n) time because every value is inspected once, and O(1) extra space because only one running-sum variable is required.

## When should you use a reference parameter?

Use a reference when a function needs access to the caller’s original object—especially when modifying it or when reading a large object without copying it.

---

# Optional completion checklist

- [ ] I can explain `std::size_t` in an index loop.
- [ ] I understand why `int& number` changes a vector value but `int number` does not.
- [ ] I can diagnose a missing-file error using `pwd` and `ls`.
- [ ] I completed one optional program or dry-run exercise.
