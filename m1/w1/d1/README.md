# Day 1 — C++ Foundations, DSA Foundations, and First Project Setup

**Time target:** 2 hours  
**Order:** complete the sections in order. Do only the “core lab” in each section today; stretch work is optional.

## What success looks like today

At the end of Day 1, you will be able to say:

> I can write and run a small C++ program, explain the difference between O(n) and O(n²), solve a basic array problem, and build a C++ command-line project with CMake and Git.

## Suggested schedule

| Section | Time | Required result |
|---|---:|---|
| 1. C++ language | 40 minutes | Build and run one small C++ program |
| 2. DSA | 45 minutes | Solve Find Largest Element without copying the answer |
| 3. Project | 35 minutes | Build and run the Log Analyzer project; make one Git commit |

Do not try to memorize every sentence. Read a small part, type the lab code yourself, run it, then answer the review questions aloud.

---

# 1. C++ Language

## 1.1 What is C++?

C++ is a programming language. You write instructions in a text file, and a **compiler** turns those instructions into a program your computer can run.

```text
You write code in a .cpp file
        ↓
The compiler checks and translates it
        ↓
An executable program is created
        ↓
You run that program in the terminal
```

For example:

```text
Source file:     hello.cpp
Executable file: hello
Run command:     ./hello
```

## 1.2 Compile, link, and run

These words appear often in C++.

| Word | Beginner explanation |
|---|---|
| Source code | The C++ text you write, normally in a `.cpp` file |
| Compiler | A program that checks and translates your C++ source code |
| Object file | An intermediate compiled file; you do not need to create it manually today |
| Linker | Combines compiled code and libraries into a runnable program |
| Executable | The final program you can run |
| Compile error | The compiler found invalid C++ before the program was created |
| Linker error | The program refers to code that was declared but not found |
| Runtime error | A problem that happens after the program begins running |

The command below compiles a file named `cpp_basics.cpp`:

```bash
g++ -std=c++20 -Wall -Wextra cpp_basics.cpp -o cpp_basics
```

Meaning:

| Part | Meaning |
|---|---|
| `g++` | The GNU C++ compiler |
| `-std=c++20` | Use modern C++20 language rules |
| `-Wall -Wextra` | Ask the compiler to show useful warnings |
| `cpp_basics.cpp` | The source file to compile |
| `-o cpp_basics` | Name the output executable `cpp_basics` |

Run the resulting program:

```bash
./cpp_basics
```

## 1.3 A minimal C++ program

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++!\n";
    return 0;
}
```

Line-by-line:

| Code | Meaning |
|---|---|
| `#include <iostream>` | Makes input/output tools such as `std::cout` available |
| `int main()` | The function where the program starts |
| `{` and `}` | Mark the beginning and end of a block of code |
| `std::cout` | Prints text to the terminal |
| `"Hello, C++!\n"` | A string of text; `\n` starts a new line |
| `return 0;` | Ends the program successfully |

## 1.4 Variables and basic types

A variable stores a value with a name.

```cpp
int year = 3;
double temperature = 24.5;
bool isReady = true;
char grade = 'A';
std::string name = "Guru";
```

| Type | Stores | Example |
|---|---|---|
| `int` | Whole numbers | `42`, `-7` |
| `double` | Decimal numbers | `3.14`, `24.5` |
| `bool` | `true` or `false` | `isReady = true` |
| `char` | One character | `'A'` |
| `std::string` | Text | `"robotics"` |

To use `std::string`, include:

```cpp
#include <string>
```

## 1.5 Input and output

Print output with `std::cout`:

```cpp
std::cout << "Enter your name: ";
```

Read input with `std::cin`:

```cpp
std::string name;
std::cin >> name;
```

If the user enters `Guru`, the variable `name` now stores `"Guru"`.

## 1.6 Conditions and loops

Use an `if` statement to choose between actions.

```cpp
if (year >= 3) {
    std::cout << "You can begin interview preparation.\n";
} else {
    std::cout << "Keep building fundamentals.\n";
}
```

Use a `for` loop to repeat work.

```cpp
for (int number = 1; number <= 3; ++number) {
    std::cout << number << '\n';
}
```

Output:

```text
1
2
3
```

## 1.7 Functions

A function is a named piece of code that does one job.

```cpp
int add(int firstNumber, int secondNumber) {
    return firstNumber + secondNumber;
}
```

| Part | Meaning |
|---|---|
| `int` before `add` | The function returns an integer |
| `add` | The function name |
| `firstNumber`, `secondNumber` | Inputs to the function, called parameters |
| `return` | Sends a result back to whoever called the function |

Call the function:

```cpp
int result = add(4, 5);
```

Now `result` is `9`.

## Core lab — build and run a C++ profile program

### Step 1: create a practice folder

Run these commands in a terminal:

```bash
cd /home/guru/Documents/ChatGPT/Roadmap2028
mkdir -p day1-practice
cd day1-practice
nano cpp_basics.cpp
```

`nano` opens a simple terminal text editor.

### Step 2: type or paste this code

```cpp
#include <iostream>
#include <string>

void printIntroduction(const std::string& name, int year) {
    std::cout << "Hello, " << name << "!\n";
    std::cout << "You are in year " << year << ".\n";
}

int main() {
    std::string name;
    int year = 0;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Enter your year of study: ";
    std::cin >> year;

    printIntroduction(name, year);

    if (year >= 3) {
        std::cout << "You are ready to begin structured interview preparation.\n";
    } else {
        std::cout << "Build fundamentals steadily.\n";
    }

    return 0;
}
```

Save in `nano` with `Ctrl + O`, press `Enter`, then exit with `Ctrl + X`.

### Step 3: compile it

```bash
g++ -std=c++20 -Wall -Wextra cpp_basics.cpp -o cpp_basics
```

If the command returns to a blank prompt with no error text, compilation succeeded.

### Step 4: run it

```bash
./cpp_basics
```

Example interaction:

```text
Enter your name: Guru
Enter your year of study: 3
Hello, Guru!
You are in year 3.
You are ready to begin structured interview preparation.
```

### Step 5: make two small changes yourself

1. Change the message printed for a student in year 1 or 2.
2. Add a `std::string branch` variable and print the branch name.

Compile and run again after each change.

## Section 1 review

Answer these without looking above.

1. What does the compiler do?
2. What is the role of `main()`?
3. What is the difference between `int` and `double`?
4. What does `std::cin` do?
5. What is a function parameter?
6. What does a compile error mean?

### Review answers

1. The compiler checks and translates C++ source code into code that can become an executable.
2. `main()` is the starting function of a C++ program.
3. `int` stores whole numbers; `double` stores decimal values.
4. `std::cin` reads input from the terminal.
5. A parameter is an input a function receives.
6. The compiler found invalid C++ syntax or types before creating a runnable program.

---

# 2. DSA — Arrays, One-Pass Thinking, and Big-O

## 2.1 What is DSA?

**Data Structures and Algorithms** means:

| Term | Meaning |
|---|---|
| Data structure | A way to organize data, such as an array, stack, queue, tree, or hash map |
| Algorithm | A step-by-step method for solving a problem |

Today’s data structure is an **array**. In C++, interview problems usually use `std::vector<int>`, which behaves like a flexible array. We will study vectors more deeply on Day 2.

## 2.2 Array basics

```text
Index:  0   1   2   3   4
Value:  8  12   3  19   5
```

An index tells you a value’s position. Indexing starts at `0`.

| Operation | Typical time complexity | Why |
|---|---:|---|
| Read `numbers[2]` | O(1) | The location is known directly |
| Change `numbers[2]` | O(1) | The location is known directly |
| Visit all values | O(n) | Every value is inspected once |
| Search an unsorted array | O(n) | The target could be anywhere |

## 2.3 What is Big-O?

Big-O describes how work grows as input size grows. It does not measure exact seconds; it describes the pattern of growth.

```text
O(1)      constant work
O(log n)  repeatedly halve the search space
O(n)      visit each item once
O(n²)     compare many pairs of items
```

Examples:

```cpp
// O(1): one direct operation
int firstValue = numbers[0];

// O(n): one loop through n values
for (int number : numbers) {
    std::cout << number << '\n';
}

// O(n²): an inner loop runs for every outer-loop iteration
for (int first = 0; first < n; ++first) {
    for (int second = 0; second < n; ++second) {
        // constant work
    }
}
```

## 2.4 The one-pass pattern

Many beginner array problems have the same shape:

```text
1. Start with a variable that stores the current answer.
2. Scan every array value once.
3. Update the answer when needed.
4. Return the answer.
```

For “find the largest value”:

```text
Input: [8, 12, 3, 19, 5]

Start largest = 8
Read 12 → largest = 12
Read 3  → largest stays 12
Read 19 → largest = 19
Read 5  → largest stays 19

Answer: 19
```

This is O(n) time because it examines every input value once. It uses O(1) extra space because it stores only one additional variable, `largest`.

## Core lab — Find Largest Element

### Problem statement

Write a function that returns the largest integer in a non-empty list.

```text
Input:  [8, 12, 3, 19, 5]
Output: 19
```

### Before coding, answer these questions

1. What variable will remember the best answer so far?  
   `largest`
2. What should its initial value be?  
   The first array value.
3. Why not initialize it to `0`?  
   A list containing only negative numbers would fail.
4. How many times must you inspect the input?  
   Once.

### Step 1: create the file

From the `day1-practice` folder:

```bash
nano find_largest.cpp
```

### Step 2: first try — complete the missing lines yourself

```cpp
#include <iostream>
#include <stdexcept>
#include <vector>

int findLargest(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        throw std::invalid_argument("Array cannot be empty.");
    }

    int largest = numbers[0];

    for (int index = 1; index < static_cast<int>(numbers.size()); ++index) {
        // If the current value is larger than largest,
        // update largest.
    }

    return largest;
}

int main() {
    std::vector<int> numbers = {8, 12, 3, 19, 5};

    std::cout << "Largest: " << findLargest(numbers) << '\n';
    return 0;
}
```

### Step 3: compile and run

```bash
g++ -std=c++20 -Wall -Wextra find_largest.cpp -o find_largest
./find_largest
```

Expected output:

```text
Largest: 19
```

### Reference solution

Use this only after making an honest attempt:

```cpp
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

### Step 4: test your program

Replace the list in `main()` and run again.

```cpp
{-8, -3, -12}  // expected: -3
{42}           // expected: 42
{5, 5, 5}      // expected: 5
{-1, 0, 1}     // expected: 1
```

## Optional DSA stretch — Two Sum

Do this only after Find Largest Element is clear.

Problem:

```text
Input:  numbers = [2, 7, 11, 15], target = 9
Output: [0, 1]
```

The key idea:

```text
For each current number:
    needed = target - current number

If needed was already seen:
    return the earlier index and current index

Otherwise:
    remember the current number and its index
```

For `[2, 7, 11, 15]` and target `9`:

```text
Read 2 → need 7 → 7 has not been seen → remember 2 at index 0
Read 7 → need 2 → 2 was seen at index 0 → answer [0, 1]
```

This uses a hash map. It takes O(n) average time and O(n) extra space.

## Section 2 review

### Questions

1. Why is direct array access O(1)?
2. Why is scanning an array O(n)?
3. Why is a nested loop often O(n²)?
4. Why is `largest = 0` unsafe for a largest-value algorithm?
5. What do “time complexity” and “space complexity” mean?
6. What does the variable `largest` represent while the loop runs?

### Review answers

1. An array index directly identifies the memory location of the value.
2. In the worst case, every one of the `n` values must be inspected.
3. If each of two loops runs about `n` times, the total work is about `n × n`.
4. A list containing only negative numbers would incorrectly return `0`.
5. Time complexity describes work/runtime growth; space complexity describes additional memory growth.
6. It is the largest value seen so far.

### Interview explanation to practice aloud

> I initialize `largest` with the first value so the algorithm works for negative numbers. I scan the remaining values once and update `largest` whenever I find a larger value. This is O(n) time and O(1) extra space.

---

# 3. Project — C++ Sensor Log Analyzer Setup

## 3.1 Project goal

Over the coming days, you will build a command-line application that reads a log file and produces useful summaries.

Today’s version does only two things:

1. Starts successfully.
2. Accepts and prints an optional log-file path.

This is intentionally small. A good project grows in small working steps.

## 3.2 Why use Git and CMake?

| Tool | Beginner explanation |
|---|---|
| Git | Saves a history of changes, like checkpoints in a game |
| CMake | Stores build instructions so the project can be built consistently |
| `.gitignore` | Lists generated files that Git should not track |

## 3.3 Check required tools

Run:

```bash
g++ --version
cmake --version
git --version
```

Each command should print a version. If one says “command not found,” stop there and ask for help before continuing.

## Core lab — initialize the project

### Step 1: create folders and initialize Git

```bash
cd /home/guru/Documents/ChatGPT/Roadmap2028
mkdir -p cpp-log-analyzer/src
mkdir -p cpp-log-analyzer/include
mkdir -p cpp-log-analyzer/tests
mkdir -p cpp-log-analyzer/data
cd cpp-log-analyzer
git init
```

The project should now look like this:

```text
cpp-log-analyzer/
├── data/
├── include/
├── src/
└── tests/
```

### Step 2: create `CMakeLists.txt`

```bash
nano CMakeLists.txt
```

Paste:

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

Meaning:

| CMake instruction | Meaning |
|---|---|
| `cmake_minimum_required` | The minimum CMake version needed |
| `project` | Sets project name, version, and language |
| `CMAKE_CXX_STANDARD 20` | Use C++20 |
| `add_executable` | Build a program named `log_analyzer` from `src/main.cpp` |
| `target_compile_options` | Enable useful compiler warnings |

Save with `Ctrl + O`, `Enter`, then `Ctrl + X`.

### Step 3: create `src/main.cpp`

```bash
nano src/main.cpp
```

Paste:

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
    std::cout << "File parsing will be added on Day 2.\n";

    return 0;
}
```

New idea: `argc` and `argv` are command-line arguments.

If you run:

```bash
./build/log_analyzer data/sample.log
```

then:

```text
argc is 2
argv[0] is ./build/log_analyzer
argv[1] is data/sample.log
```

The program checks `argc < 2` to see whether the user forgot to give a file path.

Save and exit `nano`.

### Step 4: create `.gitignore`

```bash
nano .gitignore
```

Paste:

```gitignore
build/
compile_commands.json
*.o
*.out
```

`build/` is generated by CMake, so it should not be saved in Git.

### Step 5: create a basic project README

```bash
nano README.md
```

Paste:

````md
# C++ Sensor Log Analyzer

A command-line C++ application that will read, validate, analyze, and summarize sensor or system log files.

## Current capabilities

- Builds with CMake.
- Accepts a log-file path through the command line.
- Prints application and input-file information.

## Build and run

```bash
cmake -S . -B build
cmake --build build
./build/log_analyzer data/sample.log
```
````

### Step 6: configure, build, and run

Configure the project:

```bash
cmake -S . -B build
```

Build the executable:

```bash
cmake --build build
```

Run without a file path:

```bash
./build/log_analyzer
```

Expected output:

```text
Sensor Log Analyzer
Version: 0.1.0
Usage: ./log_analyzer <log-file-path>
```

Run with a file path:

```bash
./build/log_analyzer data/sample.log
```

Expected output:

```text
Sensor Log Analyzer
Version: 0.1.0
Input file: data/sample.log
File parsing will be added on Day 2.
```

The `sample.log` file does not need to exist yet because today’s program only prints the path; it does not open the file.

### Step 7: make your first Git checkpoint

```bash
git status
git add .
git commit -m "Initialize C++ log analyzer project"
git log --oneline
```

Expected final line will look similar to:

```text
abc1234 Initialize C++ log analyzer project
```

## Section 3 review

### Questions

1. Why do we use CMake?
2. Why should `build/` be in `.gitignore`?
3. What does `git init` do?
4. What does `argc < 2` mean in this program?
5. What does `argv[1]` contain when the user provides a path?
6. What is the difference between `cmake -S . -B build` and `cmake --build build`?

### Review answers

1. CMake stores reproducible instructions for building the project.
2. It contains generated files that can be recreated; Git should track source and documentation instead.
3. It starts a new Git repository in the current folder.
4. The user did not provide the required file-path argument.
5. It contains the first user-provided command-line argument, such as `data/sample.log`.
6. The first configures build files; the second compiles the executable.

### Project completion test

- [ ] `cmake -S . -B build` succeeds.
- [ ] `cmake --build build` succeeds.
- [ ] `./build/log_analyzer` prints usage instructions.
- [ ] `./build/log_analyzer data/sample.log` prints the supplied path.
- [ ] `git log --oneline` shows the initial commit.

---

# Day 1 final checklist

## C++ language

- [ ] I compiled and ran `cpp_basics.cpp`.
- [ ] I understand `main`, variables, input/output, `if`, loops, and functions.
- [ ] I completed the Section 1 review aloud.

## DSA

- [ ] I understand array indexes and Big-O basics.
- [ ] I solved Find Largest Element myself.
- [ ] I tested negative, duplicate, and one-element inputs.
- [ ] I can explain its O(n) time and O(1) space complexity aloud.

## Project

- [ ] I created and built the Log Analyzer project.
- [ ] I ran it with and without a command-line path.
- [ ] I made an initial Git commit.

## Reflection

Write short answers before starting Day 2:

```text
The most useful thing I learned today:

The one concept I need to review:

The error or bug I encountered:

What I can now explain confidently:
```
