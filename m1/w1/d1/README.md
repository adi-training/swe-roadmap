Below is Day 1’s learning, revision, note-taking, and interview-prep block. 

## Day 1 learning block — 75–90 minutes

### 1. Understand the C++ program lifecycle

Learn this sequence:

```text
Source code (.cpp)
    ↓ compiler
Object file (.o)
    ↓ linker
Executable
    ↓ operating system loads it
Running program
```

Key ideas:

- A `.cpp` file contains C++ source code.
- The compiler checks syntax and converts source code into object code.
- The linker combines object files and libraries into an executable.
- A compile error happens before an executable is produced.
- A linker error happens when code refers to a function/symbol that was declared but not found.
- A runtime error happens after the program starts.

Useful command model:

```bash
g++ -std=c++20 -Wall -Wextra -Werror src/main.cpp -o analyzer
./analyzer
```

Meaning:

- `-std=c++20`: use modern C++ rules.
- `-Wall -Wextra`: enable useful warnings.
- `-Werror`: treat warnings as errors; useful for disciplined learning.
- `-o analyzer`: name the executable `analyzer`.

### 2. Revise essential C++ syntax

Focus only on these today:

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

Memorize:

- C++ execution starts from `int main()`.
- `#include` brings in declarations from headers.
- `std::` means the symbol belongs to the standard library namespace.
- `std::cout` prints output.
- `'\n'` is generally preferred over `std::endl` for normal output because it does not force a flush.
- Local variables exist only within their scope.
- Prefer descriptive names: `sensorCount`, not `x`.

### 3. Functions and parameters

Study this example:

```cpp
int add(int firstNumber, int secondNumber) {
    return firstNumber + secondNumber;
}
```

A function has:

- Return type: `int`
- Name: `add`
- Parameters: `firstNumber`, `secondNumber`
- Function body
- Return value

Know the difference:

```cpp
void printGreeting() {
    std::cout << "Hello\n";
}
```

`void` means the function returns no value.

For today, remember this rule:

> A function should do one clear job.

Examples of good functions for your future analyzer:

- `readFile`
- `parseLine`
- `countEvents`
- `printSummary`

### 4. Big-O fundamentals

Big-O describes how runtime or memory use grows as input size `n` grows.

Memorize this priority order:

```text
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ) < O(n!)
```

High-yield examples:

| Code pattern | Time complexity | Why |
|---|---:|---|
| Access `values[0]` | O(1) | Direct memory access |
| One loop through `n` values | O(n) | Visits each value once |
| Two nested loops through `n` values | O(n²) | Roughly `n × n` operations |
| Repeatedly divide search space in half | O(log n) | Binary search |
| Sort an array | O(n log n) | Typical comparison sort |
| Hash-map lookup, average case | O(1) | Hash directly locates bucket |
| Copy a vector of `n` values | O(n) | Every element is copied |

Ignore constants when discussing Big-O:

```text
O(3n + 20) → O(n)
O(n² + n) → O(n²)
```

Important distinction:

- **Time complexity:** How execution time grows.
- **Space complexity:** How additional memory use grows.

Example:

```text
Loop through an array and calculate a sum:
Time: O(n)
Extra space: O(1)

Create another array of the same size:
Time: O(n)
Extra space: O(n)
```

## Notes to add to `notes/day-01.md`

Copy and complete this:

```md
# Day 1 — C++ Basics and Big-O

## C++ program lifecycle

Source code → compiler → object file → linker → executable → running process.

- Compile error:
- Linker error:
- Runtime error:

## C++ syntax reminders

- `main()`:
- `#include`:
- `std::`:
- `const`:
- `'\n'` versus `std::endl`:

## Functions

A function should have one clear responsibility.

- Return type:
- Parameters:
- `void`:
- Why I should avoid putting all logic in `main()`:

## Big-O

| Pattern | Complexity | Example |
|---|---:|---|
| Direct access | O(1) | |
| One loop | O(n) | |
| Binary search | O(log n) | |
| Sorting | O(n log n) | |
| Nested loops | O(n²) | |

## My own explanations

- Explain O(n) in one sentence:
- Explain O(n²) in one sentence:
- Explain why binary search is O(log n):
- Explain time versus space complexity:

## Questions / confusion

- 
```

## Hands-on concept drills — with answers

### Drill 1: Identify the complexity

```cpp
for (int i = 0; i < n; ++i) {
    std::cout << values[i];
}
```

Answer: **O(n) time, O(1) extra space**.  
The loop runs once for every element, and no extra structure growing with `n` is created.

### Drill 2: Identify the complexity

```cpp
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        // constant work
    }
}
```

Answer: **O(n²) time, O(1) extra space**.  
For every value of `i`, the inner loop runs `n` times.

### Drill 3: Simplify Big-O

```text
5n + 100
n² + 3n + 10
2^n + n²
```

Answers:

```text
O(n)
O(n²)
O(2ⁿ)
```

### Drill 4: Classify the failure

| Situation | Answer |
|---|---|
| Missing semicolon | Compile error |
| Calling a declared function that has no definition linked into the program | Linker error |
| Dividing by zero after the program starts | Runtime error |
| Typing `std:cout` instead of `std::cout` | Compile error |
| Opening a file path that does not exist | Runtime/application error to handle gracefully |

### Drill 5: Explain the tradeoff

Question: Why is a hash map often faster than searching an array for a value?

Answer: An unsorted array requires checking values one by one, so lookup is typically O(n). A hash map computes a bucket location from the key, so lookup is O(1) on average. The tradeoff is extra memory and possible worst-case collisions.

## Day 1 interview questions and model answers

### What is the difference between compilation and linking?

Compilation translates individual C++ source files into object files and checks C++ syntax and types. Linking combines object files and required libraries to create the final executable. A missing implementation for a declared function is usually a linker error.

### What is Big-O notation?

Big-O describes how an algorithm’s resource usage grows as input size increases. It helps compare scalability by focusing on the dominant growth rate rather than machine-specific timing or constant factors.

### What is the complexity of accessing an element in an array?

Accessing an array element by index is O(1) because its memory location can be calculated directly from the base address and index.

### Why can nested loops be O(n), not always O(n²)?

Nested loops are O(n²) only when both loops independently scale through approximately `n` iterations. If the total number of inner-loop executions across the entire program is bounded by `n`, the complexity can still be O(n).

### What is the difference between time and space complexity?

Time complexity estimates how runtime grows with input size. Space complexity estimates how much additional memory an algorithm uses as input size grows.

### Why do we ignore constants in Big-O?

Big-O focuses on growth for large inputs. Hardware and implementation can change constant factors, but the dominant growth pattern—such as linear versus quadratic—determines scalability.

## Day 1 completion criteria

- [ ] I can explain source code → compilation → linking → execution.
- [ ] I can create and explain a simple C++ function.
- [ ] I can identify O(1), O(n), O(log n), and O(n²) patterns.
- [ ] I completed the concept drills without looking at answers.
- [ ] I completed the Day 1 notes file.
- [ ] I can answer the six interview questions aloud in my own words.
- [ ] Create and build `cpp-log-analyzer` with CMake.
- [ ] Run it with and without `data/sample.log`.
- [ ] Make the initial Git commit.
- [ ] Complete Day 1 notes on C++, compilation/linking, and Big-O.
- [ ] Solve **Find Largest Element** independently.
- [ ] Solve **Two Sum** independently after reviewing the guided version.
- [ ] Explain aloud why Find Largest is `O(n)` and Two Sum is `O(n)` average time.
- [ ] Write down one mistake or confusing point in your error log.
```
Optional, if time remains:

- Count Even Numbers.
- First Occurrence.
- Running Sum.
- One C++ basics program, preferably the calculator or operation counter.

Your final Day 1 self-introduction should be:

> I initialized a C++ project with CMake and Git, learned the compile-build-run workflow, practiced array traversal and Big-O analysis, and implemented one-pass array and hash-map solutions.

Once the core checklist is complete, move to Day 2.