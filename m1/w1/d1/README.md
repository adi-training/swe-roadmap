```md
# Day 1 — C++ Foundations, Big-O, Arrays, and Project Setup

**Time target:** 2 hours  
**Optional stretch work:** 30–60 minutes  
**Week:** 1  
**Goal:** Understand the C++ compile/build/run workflow, learn basic Big-O and array patterns, solve core DSA problems, and initialize a professional C++ project.

---

## Day 1 outcomes

By the end of Day 1, I should be able to:

- Explain source code → compilation → linking → executable → running program.
- Create and build a C++ project using CMake.
- Use Git to create a project checkpoint.
- Explain O(1), O(n), O(log n), and O(n²).
- Solve simple one-pass array problems.
- Explain the hash-map complement approach for Two Sum.
- Run a basic command-line application with an optional file-path argument.

---

# Recommended 2-hour plan

| Time | Activity |
|---:|---|
| 20 min | C++ program lifecycle and Big-O notes |
| 30 min | Project setup: Git, CMake, first build |
| 40 min | DSA: Find Largest Element and Two Sum |
| 15 min | Explain solutions aloud and record complexity |
| 15 min | Git commit, notes, and end-of-day review |

---

# Part 1 — Core C++ concepts

## C++ program lifecycle

```text
Source code (.cpp)
    ↓
Compiler
    ↓
Object file (.o)
    ↓
Linker
    ↓
Executable
    ↓
Operating system runs the program
```

## Important definitions

| Term | Meaning |
|---|---|
| Source code | Human-readable C++ code in `.cpp` files |
| Compiler | Converts C++ source code into object code |
| Linker | Combines object files and libraries into an executable |
| Executable | The program that can be run |
| Compile error | Syntax/type issue found before an executable is built |
| Linker error | Referenced symbol/function implementation cannot be found |
| Runtime error | Failure after the program begins running |

## Basic compile command

```bash
g++ -std=c++20 -Wall -Wextra src/main.cpp -o analyzer
./analyzer
```

| Flag | Meaning |
|---|---|
| `-std=c++20` | Use the C++20 language standard |
| `-Wall` | Enable common compiler warnings |
| `-Wextra` | Enable extra warnings |
| `-o analyzer` | Name the executable `analyzer` |

## Basic C++ syntax

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name = "Guru";
    int problemsSolved = 0;
    bool isLearning = true;

    std::cout << name << '\n';

    return 0;
}
```

## Key reminders

- C++ starts execution from `main()`.
- `#include` gives access to declarations from headers.
- `std::cout` prints output.
- `std::string` stores text.
- `'\n'` moves output to a new line.
- Prefer meaningful names such as `sensorCount` instead of `x`.
- A function should do one clear job.

---

# Part 2 — Big-O notes

## Complexity order

```text
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ) < O(n!)
```

| Pattern | Complexity | Example |
|---|---:|---|
| Direct array access | O(1) | `numbers[3]` |
| Single loop | O(n) | Scan every array element |
| Binary search | O(log n) | Halve a sorted search space |
| Sorting | O(n log n) | `std::sort` |
| Nested loops | O(n²) | Compare every pair |
| Hash-map lookup | O(1) average | Find key in `unordered_map` |

## Time and space complexity

```text
Time complexity:
How execution time grows as input size grows.

Space complexity:
How extra memory use grows as input size grows.
```

Example:

```text
Find largest value in an array:
Time: O(n)
Extra space: O(1)

Store every array value in a hash set:
Time: O(n) average
Extra space: O(n)
```

## Edge-case checklist

Before coding an array problem, ask:

- Is the array empty?
- Does it have only one element?
- Can values be negative?
- Can values repeat?
- Is an answer guaranteed?
- Could integer values overflow?
- Do I need to return a value, an index, or a boolean?

---

# Part 3 — DSA concepts

## One-pass array pattern

```text
1. Initialize an answer.
2. Visit each array element once.
3. Update the answer when needed.
4. Return the answer.
```

Example for finding the largest number:

```text
Input: [8, 12, 3, 19, 5]

largest = 8
12 is larger → largest = 12
3 is not larger
19 is larger → largest = 19
5 is not larger

Answer: 19
```

## Hash-map complement pattern

Use this when a problem asks for two values satisfying a target condition.

```text
For each current number:
    needed = target - currentNumber

    If needed was seen before:
        return the earlier index and current index

    Otherwise:
        store current number and index
```

---

# Part 4 — Core DSA practice

## 1. Find Largest Element

```text
Input:  [8, 12, 3, 19, 5]
Output: 19
```

Expected approach:

```text
Set largest to the first value.
Scan remaining values.
Replace largest whenever a larger value appears.
```

Complexity:

```text
Time: O(n)
Space: O(1)
```

Reference implementation:

```cpp
#include <stdexcept>
#include <vector>

int findLargest(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Array cannot be empty.");
    }

    int largest = numbers[0];

    for (int index = 1; index < static_cast<int>(numbers.size()); ++index) {
        if (numbers[index] > largest) {
            largest = numbers[index];
        }
    }

    return largest;
}
```

Test cases:

```cpp
{8, 12, 3, 19, 5} // 19
{-8, -3, -12}    // -3
{42}              // 42
{5, 5, 5}        // 5
```

## 2. Two Sum

```text
Input:  numbers = [2, 7, 11, 15], target = 9
Output: [0, 1]
```

Reference implementation:

```cpp
#include <unordered_map>
#include <utility>
#include <vector>

std::pair<int, int> twoSum(
    const std::vector<int>& numbers,
    int target
) {
    std::unordered_map<int, int> indexByNumber;

    for (int index = 0; index < static_cast<int>(numbers.size()); ++index) {
        int currentNumber = numbers[index];
        int neededNumber = target - currentNumber;

        if (indexByNumber.contains(neededNumber)) {
            return {indexByNumber[neededNumber], index};
        }

        indexByNumber[currentNumber] = index;
    }

    return {-1, -1};
}
```

Complexity:

```text
Time: O(n) average
Space: O(n)
```

Important:

```text
Check whether the complement exists before adding the current number.
This prevents using the same array element twice.
```

Test cases:

```cpp
{2, 7, 11, 15}, 9      // [0, 1]
{3, 2, 4}, 6           // [1, 2]
{3, 3}, 6              // [0, 1]
{-1, -2, -3, -4}, -6   // [1, 3]
```

## Optional DSA practice

| Problem | Expected complexity |
|---|---|
| Count even numbers | O(n) time, O(1) space |
| Find first target occurrence | O(n) time, O(1) space |
| Running sum | O(n) time, O(n) output space |
| Contains duplicate with hash set | O(n) average time, O(n) space |

---

# Part 5 — C++ practice programs

Complete these gradually; they are not all mandatory today.

| Program | Skills practiced |
|---|---|
| Profile printer | Input/output, strings, variables |
| Two-number calculator | Functions, arithmetic, division-by-zero validation |
| Temperature converter | Functions and formulas |
| Even/odd checker | Conditions and modulo |
| Maximum of three numbers | Conditions and comparisons |
| Sum from 1 to N | Loops and O(n) |
| Multiplication table | Loops and output formatting |
| Operation counter | Demonstrate O(n) versus O(n²) |

---

# Part 6 — Project build: C++ Sensor Log Analyzer

## Target structure

```text
cpp-log-analyzer/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── src/
│   └── main.cpp
├── include/
├── tests/
└── data/
```

## Create the project

```bash
cd /home/guru/Documents/ChatGPT/Roadmap2028
mkdir -p cpp-log-analyzer/{src,include,tests,data}
cd cpp-log-analyzer
git init
```

## `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.20)

project(LogAnalyzer VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(log_analyzer
    src/main.cpp
)

target_compile_options(log_analyzer PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
```

## `src/main.cpp`

```cpp
#include <iostream>
#include <string>

void printWelcomeMessage() {
    std::cout << "Sensor Log Analyzer\n";
    std::cout << "Version: 0.1.0\n";
}

int main(int argc, char* argv[]) {
    printWelcomeMessage();

    if (argc < 2) {
        std::cout << "Usage: ./log_analyzer <log-file-path>\n";
        return 0;
    }

    std::string filePath = argv[1];

    std::cout << "Input file: " << filePath << '\n';
    std::cout << "File parsing will be added in Day 2.\n";

    return 0;
}
```

## `.gitignore`

```gitignore
build/
compile_commands.json
*.o
*.out
```

## Build and run

```bash
cmake -S . -B build
cmake --build build
./build/log_analyzer
```

Expected output:

```text
Sensor Log Analyzer
Version: 0.1.0
Usage: ./log_analyzer <log-file-path>
```

Run with a path:

```bash
./build/log_analyzer data/sample.log
```

Expected output:

```text
Sensor Log Analyzer
Version: 0.1.0
Input file: data/sample.log
File parsing will be added in Day 2.
```

## Create the first Git checkpoint

```bash
git add .
git commit -m "Initialize C++ log analyzer project"
git log --oneline
```

---

# Part 7 — Interview questions

## What is Big-O notation?

Big-O describes how an algorithm’s time or memory usage grows as the input size grows. It focuses on the dominant growth rate rather than exact machine-specific runtime.

## What is the difference between compilation and linking?

Compilation converts individual C++ source files into object files and checks syntax/types. Linking combines object files and libraries into the final executable.

## Why is finding the largest array element O(n)?

In the worst case, every element must be inspected before confirming which value is largest.

## Why not initialize the maximum to zero?

It fails when every value is negative. For example, `[-8, -3, -12]` would incorrectly return `0`.

## Why is Two Sum with a hash map O(n)?

Each element is processed once, and hash-map lookup/insertion is O(1) on average. Therefore, total average time is O(n).

---

# Part 8 — Day 1 completion checklist

## Mandatory

- [ ] I understand source code → compiler → linker → executable.
- [ ] I can explain O(1), O(n), O(log n), and O(n²).
- [ ] I built and ran the CMake project.
- [ ] I created the initial Git commit.
- [ ] I solved Find Largest Element.
- [ ] I solved or fully understood Two Sum.
- [ ] I wrote Day 1 notes.
- [ ] I can explain both DSA solutions aloud.

## Optional

- [ ] I completed Count Even Numbers.
- [ ] I completed First Occurrence.
- [ ] I completed Running Sum.
- [ ] I completed Contains Duplicate.
- [ ] I completed one C++ practice program.
- [ ] I recorded a short demo of the CLI project.

---

# Day 1 retrospective

## What I learned

- 

## DSA mistakes or confusing concepts

- 

## C++ or command-line errors I encountered

- 

## Concepts to revise

- 

## What I will do differently tomorrow

- 
```