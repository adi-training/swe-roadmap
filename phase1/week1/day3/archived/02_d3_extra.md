# Day 3 Extra — Multi-File Debugging, CSV Parsing Details, and Prefix-Sum Practice

This is optional support for `DAY_03_README.md`. Complete the main Day 3 guide first.

---

# 1. Multi-file C++ clarifications

## 1.1 Declaration versus definition

Use this simple rule:

```text
Header (.hpp) → tells other files what exists.
Source (.cpp) → contains the actual code.
```

Example declaration in `greeting.hpp`:

```cpp
std::string createGreeting(const std::string& name);
```

Example definition in `greeting.cpp`:

```cpp
std::string createGreeting(const std::string& name) {
    return "Hello, " + name + "!";
}
```

The declaration is like a menu item. The definition is the kitchen that makes it.

## 1.2 Why use quotes for project headers?

```cpp
#include "log_parser.hpp"
```

Double quotes tell the compiler to look for a project header in the project’s include locations.

```cpp
#include <vector>
```

Angle brackets are normally used for standard-library headers.

## 1.3 Common multi-file errors

| Error | Likely reason | Fix |
|---|---|---|
| `log_parser.hpp: No such file or directory` | Compiler/CMake cannot find `include/` | Add the include directory, then configure CMake again |
| `undefined reference to parseLogLine` | Declaration exists but `log_parser.cpp` was not compiled/linked | Add `src/log_parser.cpp` to `add_executable` |
| `multiple definition` | Function definition was placed in a header included by multiple files | Put ordinary function definitions in `.cpp` files |
| `not declared in this scope` | Missing header include or wrong namespace | Include the correct header and use `log_analyzer::` |
| Signature mismatch | Header declaration differs from source definition | Ensure return type, name, and parameter types match exactly |

## 1.4 Why `namespace log_analyzer` is repeated

The header and source must place the parser in the same namespace.

```cpp
namespace log_analyzer {
    bool parseLogLine(...);
}
```

Outside the namespace, write:

```cpp
log_analyzer::parseLogLine(...);
```

---

# 2. CSV parsing details

## 2.1 What does `std::stringstream` do?

```cpp
std::stringstream lineStream(line);
```

This lets a string behave like a small input source.

For this line:

```text
2026-09-20 10:00:01,INFO,Temperature sensor started
```

these calls read one field at a time:

```cpp
std::getline(lineStream, timestamp, ',');
std::getline(lineStream, level, ',');
std::getline(lineStream, message);
```

Result:

```text
timestamp = "2026-09-20 10:00:01"
level     = "INFO"
message   = "Temperature sensor started"
```

## 2.2 Why no comma after `message`?

The first two calls stop at a comma. The final call has no delimiter, so it reads the remaining text.

```text
timestamp,level,message
          ↑     ↑      ↑ rest of the line
```

## 2.3 Current CSV limitation

This Day 3 parser is intentionally simple. It does **not** correctly handle a message containing commas:

```text
2026-09-20 10:00:01,INFO,Temperature reading: 24.5, stable
```

For now, keep sample messages comma-free. Full CSV parsing has quoting rules and is a later improvement.

## 2.4 Extra parsing tests

Add each line to `data/sample.log`, run the program, and predict the result before checking.

| Input line | Expected result |
|---|---|
| `2026-09-20,INFO,Started` | Valid |
| `2026-09-20,INFO,` | Invalid: empty message |
| `2026-09-20,,Started` | Invalid: empty level |
| `,INFO,Started` | Invalid: empty timestamp |
| `only one field` | Invalid: missing commas/fields |

---

# 3. Prefix-sum edge cases

## 3.1 Why use `right + 1`?

The prefix array has one extra leading `0`.

```text
Values: [2, 5, 1, 3, 4]
Prefix: [0, 2, 7, 8, 11, 15]
```

For range `[1, 3]`, you want values at indexes 1, 2, and 3:

```text
prefix[4] - prefix[1]
11 - 2 = 9
```

`prefix[4]` includes values through original index 3. The extra `+1` aligns the two arrays.

## 3.2 Valid query rules

For an array with `n` values:

```text
0 <= left <= right < n
```

Examples for five values:

| Query | Valid? | Reason |
|---|---|---|
| `[0, 0]` | Yes | First single value |
| `[0, 4]` | Yes | Entire array |
| `[2, 2]` | Yes | One value in the middle |
| `[-1, 2]` | No | Negative index |
| `[3, 5]` | No | Index 5 is outside array |
| `[4, 2]` | No | Left cannot be greater than right |

## 3.3 Optional safer range function

After completing the core implementation, add input validation:

```cpp
#include <stdexcept>

int rangeSum(
    const std::vector<int>& prefixSums,
    int left,
    int right
) {
    int originalSize = static_cast<int>(prefixSums.size()) - 1;

    if (left < 0 || right < left || right >= originalSize) {
        throw std::invalid_argument("Invalid range.");
    }

    return prefixSums[right + 1] - prefixSums[left];
}
```

Do not worry if exceptions are still unfamiliar. The important concept is validating indexes before accessing a vector.

---

# 4. Optional practice programs

## Practice A — Prefix sum printer

Input:

```text
[2, 5, 1, 3, 4]
```

Expected output:

```text
[0, 2, 7, 8, 11, 15]
```

Goal: build and print the prefix array without implementing range queries yet.

## Practice B — Count log levels

After parsing valid entries, count how many are `INFO`, `WARNING`, and `ERROR`.

Expected result for the Day 3 sample file:

```text
INFO: 2
WARNING: 1
ERROR: 1
```

Hint: Start with three integer counters. You will use `std::unordered_map` later; do not introduce it here unless you are comfortable.

## Practice C — Print only error entries

After parsing the file, print only entries whose level is `ERROR`.

Expected output:

```text
[2026-09-20 10:00:20] ERROR: Sensor connection lost
```

Goal: practice a vector traversal and a string comparison.

---

# 5. Interview rehearsal

## Why separate parsing logic from `main.cpp`?

Parsing is a distinct responsibility. Separating it makes the project easier to read, test, reuse, and change without making `main.cpp` large and complicated.

## Why do prefix sums make range queries faster?

The prefix array stores cumulative totals. A range sum can be calculated by subtracting two stored totals instead of scanning every value in the range.

## What does a struct represent in this project?

A `LogEntry` struct represents one structured log record with related fields: timestamp, level, and message.

## Why return `false` from `parseLogLine` instead of crashing?

Input data can be malformed. Returning `false` lets the caller report the problem and skip only the invalid row while continuing to process valid data.

---

# Optional completion checklist

- [ ] I can explain declarations versus definitions.
- [ ] I can diagnose the common header/linker errors in the table.
- [ ] I understand how the three CSV fields are extracted.
- [ ] I can calculate a prefix-sum range manually.
- [ ] I completed one optional practice program.
