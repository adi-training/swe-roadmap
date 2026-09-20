# Day 2 — Vectors, References, File Input, and Array Traversal

**Time target:** 2 hours  
**Week:** 1  
**Goal:** Learn to work with C++ vectors, understand pass-by-reference and `const`, read a text file safely, and practice array traversal problems.

---

## Day 2 outcomes

By the end of Day 2, I should be able to:

- Explain the difference between an array and `std::vector`.
- Use vectors to store and traverse values.
- Explain pass-by-value versus pass-by-reference.
- Explain why `const std::vector<int>&` is commonly used in C++ functions.
- Open and read a text file using `std::ifstream`.
- Handle a missing or unreadable file safely.
- Solve array traversal problems in O(n) time.
- Update the Sensor Log Analyzer to count and preview file lines.

---

# Recommended 2-hour plan

| Time | Activity |
|---:|---|
| 25 min | Learn vectors, references, and `const` |
| 25 min | Learn file input and error handling |
| 40 min | DSA: array traversal and two-pointer basics |
| 20 min | Update and run the Sensor Log Analyzer |
| 10 min | Notes, Git commit, and self-review |

---

# Part 1 — `std::vector`

## What is a vector?

A vector is a dynamic array in C++.

```cpp
#include <vector>

std::vector<int> numbers = {4, 8, 15, 16, 23, 42};
```

Unlike a fixed-size array, a vector can grow and shrink.

```cpp
numbers.push_back(99);
```

Now:

```text
[4, 8, 15, 16, 23, 42, 99]
```

## Common vector operations

| Operation | Example | Complexity |
|---|---|---:|
| Read by index | `numbers[0]` | O(1) |
| Update by index | `numbers[0] = 10` | O(1) |
| Add to end | `numbers.push_back(5)` | O(1) amortized |
| Remove from end | `numbers.pop_back()` | O(1) |
| Get size | `numbers.size()` | O(1) |
| Traverse all values | loop through vector | O(n) |
| Insert/remove in middle | `insert`, `erase` | O(n) |

## Traversing vectors

Use a range-based loop when only the value matters:

```cpp
for (int number : numbers) {
    std::cout << number << '\n';
}
```

Use an index-based loop when the index matters:

```cpp
for (std::size_t index = 0; index < numbers.size(); ++index) {
    std::cout << numbers[index] << '\n';
}
```

## Array versus vector

| Feature | Fixed array | `std::vector` |
|---|---|---|
| Size | Usually fixed | Can grow or shrink |
| Memory management | More manual | Managed automatically |
| Common interview use | Sometimes | Very common |
| Add values | Not flexible | `push_back()` |
| Safe size access | Manual tracking may be needed | `.size()` available |

---

# Part 2 — Pass-by-value, reference, and `const`

## Pass-by-value

```cpp
void addOne(int number) {
    number += 1;
}
```

This makes a copy of `number`.

```text
Original value remains unchanged outside the function.
```

## Pass-by-reference

```cpp
void addOne(int& number) {
    number += 1;
}
```

The `&` means the function receives a reference to the original variable.

```text
The original value changes.
```

## Constant reference

```cpp
int findLargest(const std::vector<int>& numbers) {
    // Read numbers, but do not modify them.
}
```

This is common because:

- `const` prevents accidental modification.
- `&` avoids copying the whole vector.
- It is efficient and communicates intent clearly.

## Rule of thumb

| Situation | Function parameter |
|---|---|
| Small value such as `int`, `double`, `bool` | Pass by value |
| Read a large object/vector/string | `const Type&` |
| Need to modify caller’s object | `Type&` |
| Optional ownership transfer | Advanced topic; learn later |

---

# Part 3 — Reading a file with `std::ifstream`

To read a file, include:

```cpp
#include <fstream>
```

Example:

```cpp
std::ifstream inputFile(filePath);
```

Always check whether the file opened successfully:

```cpp
if (!inputFile.is_open()) {
    std::cerr << "Error: Could not open file.\n";
    return;
}
```

Read a file line by line:

```cpp
std::string line;

while (std::getline(inputFile, line)) {
    std::cout << line << '\n';
}
```

## Important terms

| Term | Meaning |
|---|---|
| `std::ifstream` | Input file stream used to read files |
| `std::getline` | Reads one complete line from a stream |
| `std::cerr` | Prints error messages |
| `is_open()` | Checks whether a file opened successfully |
| EOF | End of file; reached after the last line |

---

# Part 4 — DSA concepts

## Array traversal

Traversal means visiting each value exactly once.

```text
Input: [4, 7, 1, 9]

Visit 4
Visit 7
Visit 1
Visit 9
```

This normally takes O(n) time.

## Running total pattern

Use this when calculating a sum, count, average, minimum, or maximum.

```text
1. Initialize a variable.
2. Traverse every value.
3. Update the variable.
4. Return the final result.
```

Example:

```text
Input: [4, 7, 1, 9]

sum = 0
sum = 0 + 4 = 4
sum = 4 + 7 = 11
sum = 11 + 1 = 12
sum = 12 + 9 = 21
```

## Two-pointer introduction

Two pointers are two indexes that move through an array.

For example, to move zeroes to the end:

```text
Input:  [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
```

One pointer finds the next non-zero value.  
The other pointer marks where the next non-zero value should be placed.

This is a foundation for later two-pointer and sliding-window problems.

---

# Part 5 — Core DSA practice

## 1. Calculate sum and average

```text
Input:  [4, 7, 1, 9]
Output:
Sum: 21
Average: 5.25
```

Expected complexity:

```text
Time: O(n)
Space: O(1)
```

Reference implementation:

```cpp
#include <vector>

double calculateAverage(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return 0.0;
    }

    int sum = 0;

    for (int number : numbers) {
        sum += number;
    }

    return static_cast<double>(sum) / numbers.size();
}
```

## 2. Move zeroes to the end

```text
Input:  [0, 1, 0, 3, 12]
Output: [1, 3, 12, 0, 0]
```

Expected complexity:

```text
Time: O(n)
Space: O(1)
```

Reference implementation:

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

Test cases:

```cpp
{0, 1, 0, 3, 12}  // {1, 3, 12, 0, 0}
{0, 0, 0}         // {0, 0, 0}
{1, 2, 3}         // {1, 2, 3}
{}                 // {}
{5}                // {5}
```

## 3. Optional: Find both minimum and maximum

```text
Input:  [8, -2, 15, 4, 0]
Output:
Minimum: -2
Maximum: 15
```

Expected complexity:

```text
Time: O(n)
Space: O(1)
```

---

# Part 6 — Hands-on project update

Update `src/main.cpp` in the Sensor Log Analyzer.

```cpp
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void printWelcomeMessage() {
    std::cout << "Sensor Log Analyzer\n";
    std::cout << "Version: 0.2.0\n";
}

void analyzeFile(const std::string& filePath) {
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file: "
                  << filePath
                  << '\n';
        return;
    }

    std::size_t lineCount = 0;
    std::vector<std::string> previewLines;
    std::string line;

    while (std::getline(inputFile, line)) {
        ++lineCount;

        if (previewLines.size() < 3) {
            previewLines.push_back(line);
        }
    }

    std::cout << "File opened successfully.\n";
    std::cout << "Total lines: " << lineCount << "\n\n";
    std::cout << "First " << previewLines.size() << " line(s):\n";

    for (const std::string& previewLine : previewLines) {
        std::cout << previewLine << '\n';
    }
}

int main(int argc, char* argv[]) {
    printWelcomeMessage();

    if (argc < 2) {
        std::cout << "Usage: ./log_analyzer <log-file-path>\n";
        return 0;
    }

    analyzeFile(argv[1]);

    return 0;
}
```

## Create sample data

Create `data/sample.log`:

```bash
nano data/sample.log
```

Add:

```text
2026-09-20 10:00:01 INFO Temperature sensor started
2026-09-20 10:00:05 INFO Temperature reading: 24.5
2026-09-20 10:00:10 WARNING Battery level low
2026-09-20 10:00:15 ERROR Sensor connection lost
2026-09-20 10:00:20 INFO Reconnecting to sensor
```

Build and run:

```bash
cmake --build build
./build/log_analyzer data/sample.log
```

Expected output:

```text
Sensor Log Analyzer
Version: 0.2.0
File opened successfully.
Total lines: 5

First 3 line(s):
2026-09-20 10:00:01 INFO Temperature sensor started
2026-09-20 10:00:05 INFO Temperature reading: 24.5
2026-09-20 10:00:10 WARNING Battery level low
```

Test error handling:

```bash
./build/log_analyzer data/missing.log
```

Expected output:

```text
Sensor Log Analyzer
Version: 0.2.0
Error: Could not open file: data/missing.log
```

Commit the update:

```bash
git add .
git commit -m "Add file reading and log preview"
```

---

# Part 7 — Interview questions

## Why use `const std::vector<int>&` as a parameter?

It avoids copying a potentially large vector, improving efficiency. The `const` keyword ensures the function cannot modify the original vector.

## What is the difference between pass-by-value and pass-by-reference?

Pass-by-value creates a copy, so changes inside the function do not affect the caller. Pass-by-reference gives access to the original object, so modifications can affect the caller.

## What is the time complexity of traversing a vector?

O(n), because each of the `n` elements is visited once.

## Why use `std::vector` instead of a fixed-size array?

Vectors manage memory automatically, track their size, can grow dynamically, and provide useful operations such as `push_back()`.

## Why must a program check whether a file opened successfully?

A file may be missing, have incorrect permissions, or be inaccessible. Checking prevents the program from continuing with invalid input and allows a useful error message.

## What is the complexity of moving zeroes using two pointers?

O(n) time because the array is traversed once, and O(1) extra space because values are rearranged in the original vector.

---

# Day 2 completion checklist

## Mandatory

- [ ] I can explain vector access and traversal complexity.
- [ ] I understand pass-by-value, `Type&`, and `const Type&`.
- [ ] I understand how `std::ifstream` and `std::getline` work.
- [ ] I solved Calculate Sum and Average.
- [ ] I solved or understood Move Zeroes.
- [ ] My analyzer opens and counts a real file.
- [ ] My analyzer prints the first three lines.
- [ ] My analyzer handles a missing file without crashing.
- [ ] I made a Git commit.

## Optional

- [ ] I solved Find Minimum and Maximum.
- [ ] I added a test file with blank lines.
- [ ] I added command-line validation for extra arguments.
- [ ] I wrote a short explanation of vectors versus arrays.
- [ ] I re-solved Find Largest Element from Day 1 without help.

---

# Day 2 retrospective

## What I learned

- 

## Errors or bugs I encountered

- 

## DSA concepts to revise

- 

## C++ concepts to revise

- 

## Project improvement for Day 3

- 
````