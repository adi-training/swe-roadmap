Think of this as setting up an empty but well-organized workshop before building the actual analyzer.

You are not building the full application today. You are creating a C++ project that can reliably compile and run.

## The big picture

```text
Your C++ code
    ↓
CMake reads build instructions
    ↓
Compiler turns code into an executable
    ↓
You run the executable in the terminal
```

Your project will eventually read sensor/log files. Today it only accepts a file name and prints it.

## 1. Project folders

This structure keeps code organized:

```text
cpp-log-analyzer/
├── CMakeLists.txt     ← Build instructions
├── README.md          ← Project documentation
├── .gitignore         ← Files Git should not track
├── src/               ← Your C++ code
│   └── main.cpp
├── include/           ← Header files later
├── tests/             ← Automated tests later
└── data/              ← Sample log files later
```

On Linux/macOS:

```bash
mkdir -p cpp-log-analyzer/src
mkdir -p cpp-log-analyzer/include
mkdir -p cpp-log-analyzer/tests
mkdir -p cpp-log-analyzer/data
cd cpp-log-analyzer
```

`mkdir` means “make directory.”  
`cd` means “change directory,” or move into that folder.

## 2. What is Git?

Git remembers the history of your project.

```bash
git init
```

This tells Git:

> “Start tracking versions of the files in this folder.”

Later, you save a checkpoint with:

```bash
git add .
git commit -m "Initialize C++ log analyzer project"
```

- `git add .` selects all current changes.
- `git commit` creates a named checkpoint.
- The message explains what changed.

## 3. What is `main.cpp`?

This is the starting point of a C++ application. When you run the program, C++ starts from `main()`.

```cpp
#include <iostream>
#include <string>
```

These lines import standard C++ tools:

- `<iostream>` gives you `std::cout`, used to print text.
- `<string>` gives you `std::string`, used to store text.

```cpp
void printWelcomeMessage() {
    std::cout << "Sensor Log Analyzer\n";
    std::cout << "Version: 0.1.0\n";
}
```

This creates a function named `printWelcomeMessage`.

- `void` means it does not return a value.
- The function’s only job is to print a welcome message.
- Splitting work into small functions keeps code readable.

```cpp
int main(int argc, char* argv[]) {
```

This is the program entry point.

The two parameters allow your program to receive values from the terminal:

- `argc` means **argument count**.
- `argv` means **argument vector**.

If you run:

```bash
./build/log_analyzer data/sample.log
```

Then the program receives:

```text
argc = 2

argv[0] = ./build/log_analyzer
argv[1] = data/sample.log
```

So this check:

```cpp
if (argc < 2) {
    std::cout << "Usage: ./log_analyzer <log-file-path>\n";
    return 0;
}
```

means:

> “If the user did not provide a file path, show them how to use the program and exit safely.”

Then:

```cpp
std::string filePath = argv[1];
```

stores the provided file path in a clearer variable.

Today, we only print this path. On Day 2, you will learn to open and read the actual file.

## 4. What is CMake?

CMake is a tool that generates the instructions needed to compile your program.

Instead of manually writing a long compiler command every time, you put build rules in:

```text
CMakeLists.txt
```

The key lines are:

```cmake
project(LogAnalyzer VERSION 0.1.0 LANGUAGES CXX)
```

This sets the project name, version, and language.

```cmake
set(CMAKE_CXX_STANDARD 20)
```

This says:

> “Compile this project using the C++20 standard.”

```cmake
add_executable(log_analyzer
    src/main.cpp
)
```

This says:

> “Create an executable named `log_analyzer` using the source code in `src/main.cpp`.”

```cmake
target_compile_options(log_analyzer PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
```

These enable warnings. Warnings are messages from the compiler such as:

> “This variable is unused”  
> “This conversion may lose information”

For a beginner, warnings are valuable feedback. Treat them as learning opportunities.

## 5. Configure, build, run

Run these commands from inside the `cpp-log-analyzer` folder:

```bash
cmake -S . -B build
```

Meaning:

```text
-S .       Source folder is the current folder
-B build   Put generated build files in a folder named build
```

Then compile:

```bash
cmake --build build
```

This turns `src/main.cpp` into the executable:

```text
build/log_analyzer
```

Finally, run it:

```bash
./build/log_analyzer
```

You should see:

```text
Sensor Log Analyzer
Version: 0.1.0
Usage: ./log_analyzer <log-file-path>
```

This is expected because you did not give a file path.

Try again with a sample path:

```bash
./build/log_analyzer data/sample.log
```

You do not need to create `sample.log` yet, because the program is only printing its name at this stage.

Expected output:

```text
Sensor Log Analyzer
Version: 0.1.0
Input file: data/sample.log
File parsing will be added in Day 2.
```

## 6. Why ignore `build/`?

The `build/` directory is generated automatically by CMake and the compiler. It can be deleted and recreated at any time.

That is why `.gitignore` contains:

```gitignore
build/
```

Git should track source code and documentation—not generated files.

## Your Day 1 success condition

You are done when you understand this sentence:

> I wrote C++ source code in `src/main.cpp`, CMake used `CMakeLists.txt` to compile it into `build/log_analyzer`, and I ran that executable with an optional command-line file path.

