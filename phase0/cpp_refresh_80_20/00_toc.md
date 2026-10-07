# C++ 80:20 Refresh — Hands-On Roadmap for DSA

## Goal

This is an **8–10 hour practical C++ refresher** designed for someone who already has some exposure to C++ but wants to quickly rebuild confidence before starting DSA training.

The emphasis is on:

- Core syntax you will use constantly in DSA
- Writing small programs instead of only reading theory
- Understanding **arrays, strings, references, pointers, functions, structs/classes**
- Getting comfortable with the small subset of the STL that makes DSA practice productive
- Learning enough Big-O and problem-solving habits to transition into DSA smoothly

This is **not** a complete C++ course. Advanced topics such as inheritance, virtual functions, templates in depth, smart-pointer design, exceptions, concurrency, file I/O, and metaprogramming are intentionally postponed.

---

## How to use these files

For every chapter:

1. Read the explanation quickly.
2. Type the examples yourself.
3. Solve the exercises **without looking at the solution first**.
4. Compile after each small change.
5. When stuck, write down what you know, what you expect, and what the program actually does.
6. Move on once you can solve most exercises comfortably.

A useful rule for this refresher:

> **20% reading, 80% writing/running/debugging code.**

---

## 8–10 Hour Schedule

| Chapter | Topic | Suggested time |
|---|---|---:|
| 01 | Basics, input/output, types, variables | 45 min |
| 02 | Operators, conditions, loops | 60 min |
| 03 | Functions, scope, recursion | 60 min |
| 04 | Arrays, strings, vectors | 75 min |
| 05 | References, pointers, dynamic memory | 50 min |
| 06 | Structs, classes, constructors | 50 min |
| 07 | Essential STL for DSA | 90 min |
| 08 | DSA-ready coding patterns + complexity | 60 min |
| 09 | Capstone hands-on practice | 90 min |
| **Total** |  | **~9.5 hours** |

You can shorten any chapter by skipping the optional exercises.

---

## Files

1. `01_basics_io_types.md`
2. `02_operators_conditions_loops.md`
3. `03_functions_scope_recursion.md`
4. `04_arrays_strings_vectors.md`
5. `05_references_pointers_memory.md`
6. `06_structs_classes.md`
7. `07_stl_essentials.md`
8. `08_dsa_ready_patterns_complexity.md`
9. `09_capstone_practice.md`

---

## Recommended setup

A recent GCC/Clang compiler is enough. Prefer **C++17** for this refresher.

Compile:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic program.cpp -o program
./program
```

For a quick one-file experiment:

```bash
echo '#include <iostream>\nint main(){ std::cout << "Hello\\n"; }' > hello.cpp
g++ -std=c++17 hello.cpp -o hello && ./hello
```

---

## DSA transition checklist

By the end, you should be able to comfortably:

- Read input and print output
- Choose between `int`, `long long`, `double`, `char`, `bool`, and `std::string`
- Write `if`, `switch`, `for`, `while`, and nested loops
- Write functions with parameters and return values
- Understand pass-by-value vs pass-by-reference
- Use arrays and `std::vector`
- Traverse and modify sequences
- Manipulate strings
- Understand pointers at a practical level
- Define simple structs/classes
- Use `vector`, `pair`, `sort`, `reverse`, `map`, `unordered_map`, `set`, `stack`, and `queue`
- Estimate basic time and space complexity
- Break a problem into helper functions
- Debug simple compile-time, runtime, and logic errors

---

## Practice philosophy

When solving DSA problems, avoid jumping straight to clever code. Use this sequence:

```text
Understand the problem
        ↓
Write examples
        ↓
Identify input/output
        ↓
Describe a simple algorithm in words
        ↓
Choose data structures
        ↓
Estimate complexity
        ↓
Write code
        ↓
Test edge cases
```

That workflow is more important than memorizing syntax.

