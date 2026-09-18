Next is the Day 1 build task: create the foundation for your **C++ Sensor Log Analyzer**.

Today, do not parse real CSV data yet. The goal is simply a professional project structure that compiles, runs, and is tracked with Git.

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

## Step 1: Create the project

```bash
mkdir -p cpp-log-analyzer/{src,include,tests,data}
cd cpp-log-analyzer
git init
```

## Step 2: Add `CMakeLists.txt`

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

## Step 3: Add `src/main.cpp`

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

## Step 4: Add `.gitignore`

```gitignore
build/
compile_commands.json
*.o
*.out
```

## Step 5: Add a starter `README.md`

```md
# C++ Sensor Log Analyzer

A command-line C++ application that will read, validate, analyze, and summarize sensor or system log files.

## Current capabilities

- Builds with CMake.
- Accepts a log-file path through the command line.
- Prints application and input-file information.

## Planned capabilities

- Read CSV/text log files.
- Validate malformed rows.
- Count event types and error categories.
- Generate summary reports.
- Add automated tests.

## Build and run

```bash
cmake -S . -B build
cmake --build build
./build/log_analyzer data/sample.log
```
```

## Step 6: Build and run

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

Then run:

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

## Step 7: Commit it

```bash
git add .
git commit -m "Initialize C++ log analyzer project"
```

## Interview-ready explanation

> I set up the project using CMake to make builds reproducible and scalable as the codebase grows. I separated source code, headers, tests, and sample data from the beginning, and enabled compiler warnings to catch issues early. The initial command-line interface accepts an input path, establishing the contract for the file-processing features I will add next.

## Completion checklist

- [ ] Project folders created.
- [ ] CMake build succeeds.
- [ ] Program runs with and without a file-path argument.
- [ ] README has build and usage instructions.
- [ ] Build directory is ignored by Git.
- [ ] Initial commit is created.