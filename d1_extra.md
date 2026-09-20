# Day 1 Extra — Clarifications, Debugging, and Optional Practice

This is a supplement to `DAY_01_README.md`, not a replacement. Complete the core Day 1 guide first. Use this file only when you have extra time or encounter a confusing line of code.

---

# 1. C++ details used in Day 1

## 1.1 What does `std::` mean?

The C++ standard library contains useful tools made available by C++. Those tools live in a named area called the **standard namespace**, written as `std`.

```cpp
std::cout
std::cin
std::string
std::vector
```

The `::` symbol means “inside.”

```text
std::cout means: cout inside the standard library namespace.
```

For now, always write `std::` explicitly. It makes code clearer and avoids naming conflicts.

## 1.2 Why do we write `#include`?

`#include` makes declarations from a library header available before compilation.

| Header | Gives access to |
|---|---|
| `#include <iostream>` | `std::cout`, `std::cin`, `std::cerr` |
| `#include <string>` | `std::string` |
| `#include <vector>` | `std::vector` |
| `#include <stdexcept>` | error types such as `std::invalid_argument` |

If you write `std::vector<int>` but forget `#include <vector>`, compilation will fail because the compiler does not yet know what a vector is.

## 1.3 `char` versus `std::string`

```cpp
char grade = 'A';
std::string name = "Guru";
```

| Type | Stores | Quotes |
|---|---|---|
| `char` | Exactly one character | Single quotes: `'A'` |
| `std::string` | Text containing zero or more characters | Double quotes: `"Guru"` |

## 1.4 The meaning of `const std::string&`

You saw this function:

```cpp
void printIntroduction(const std::string& name, int year) {
    // Read name, but do not change it.
}
```

Read it from right to left:

```text
name is a reference (&) to a string.
const means this function promises not to change that string.
```

Why use it?

```text
std::string name         → creates a copy of the text for the function
const std::string& name  → reads the original text without copying it
```

For Day 1, remember only this rule:

> Use `const Type&` when a function needs to read a larger object, such as a string or vector, without changing it.

You will practice references and vectors more deeply on Day 2.

## 1.5 The minimum `std::vector` knowledge needed today

`std::vector<int>` stores a list of integers.

```cpp
std::vector<int> numbers = {8, 12, 3, 19, 5};
```

```text
Index:     0   1  2   3  4
Value:     8  12  3  19  5
```

Useful Day 1 operations:

```cpp
numbers[0]        // first value: 8
numbers.size()    // number of values: 5
numbers.empty()   // false when it contains values
```

---

# 2. Debugging and compiler feedback

## 2.1 Read errors from top to bottom

When compilation fails:

1. Read the **first** error message first.
2. Find the filename and line number.
3. Fix that error.
4. Compile again.
5. Repeat until no errors remain.

One missing semicolon can cause several later error messages. Fixing the first error often removes the rest.

## 2.2 Common beginner errors

| Problem | Example | Fix |
|---|---|---|
| Missing semicolon | `int age = 20` | Add `;` |
| Misspelled name | `std:cout` | Write `std::cout` |
| Missing header | use `std::string` without `<string>` | Add `#include <string>` |
| Wrong quote type | `char letter = "A";` | Use `'A'` for `char` |
| Unmatched braces | missing `}` | Count opening and closing braces |
| Wrong file name | compile `main.cpp` when file is `program.cpp` | Use the actual file name |

## Debugging lab

Create a file named `debug_practice.cpp` and paste this deliberately broken code:

```cpp
#include <iostream>

int main() {
    int number = 10
    std:cout << number << "\n";
    return 0;
}
```

Compile it:

```bash
g++ -std=c++20 -Wall -Wextra debug_practice.cpp -o debug_practice
```

Fix the errors yourself. The correct version is:

```cpp
#include <iostream>

int main() {
    int number = 10;
    std::cout << number << "\n";
    return 0;
}
```

---

# 3. Optional C++ practice programs

These programs reinforce Day 1 language concepts. Do one or two only after the core guide is complete.

## Practice A — Two-number calculator

### Requirements

1. Read two decimal numbers.
2. Use separate functions for addition, subtraction, multiplication, and division.
3. Handle division by zero safely.

Example:

```text
Input first number: 12
Input second number: 4

Sum: 16
Difference: 8
Product: 48
Quotient: 3
```

### Suggested functions

```cpp
double add(double first, double second);
double subtract(double first, double second);
double multiply(double first, double second);
```

For division, first check:

```cpp
if (second == 0) {
    // Print a useful error instead of dividing.
}
```

### Expected learning

You can accept input, call functions, return values, and use `if/else` for safe behavior.

## Practice B — Number classifier

### Requirements

Read one integer and print:

- Whether it is positive, negative, or zero.
- Whether it is even or odd.

Example:

```text
Input: -14
Output: Negative even number
```

Hint:

```cpp
number % 2 == 0
```

means “the number is even.”

## Practice C — Operation counter

### Goal

See the difference between O(n) and O(n²) using visible counts.

### Requirements

1. Read a positive integer `n`.
2. Run one loop from `0` to `n - 1`; count its iterations.
3. Run a nested loop from `0` to `n - 1`; count its inner operations.
4. Print both totals.

Example for `n = 4`:

```text
Single-loop operations: 4
Nested-loop operations: 16
```

Run it with `n = 10`:

```text
Single-loop operations: 10
Nested-loop operations: 100
```

Expected learning:

```text
One loop scales roughly as n.
Two independent nested loops scale roughly as n × n.
```

---

# 4. Optional DSA practice

## Count even numbers

### Problem

Return how many values in an array are even.

```text
Input:  [4, 7, 0, -2, 11, 18]
Output: 4
```

### Thinking process

```text
What answer changes as I scan? → count
How do I identify an even number? → number % 2 == 0
Do I need to store another array? → no
```

### Pseudocode

```text
count = 0

For every number:
    If number is even:
        increase count

Return count
```

### Reference solution

```cpp
#include <vector>

int countEvenNumbers(const std::vector<int>& numbers) {
    int count = 0;

    for (int number : numbers) {
        if (number % 2 == 0) {
            ++count;
        }
    }

    return count;
}
```

### Complexity

```text
Time: O(n), because every value is inspected once.
Space: O(1), because only one counter is used.
```

## Dry-run worksheet

Before running code, fill this table manually for the input `[4, 7, 0, -2]`.

| Current number | Is it even? | Count after this step |
|---:|---|---:|
| 4 | | |
| 7 | | |
| 0 | | |
| -2 | | |

Correct final answer: `3`.

---

# 5. Final extra review

## Explain these aloud

1. Why do we include `<iostream>`?
2. What does `std::` mean?
3. Why does `const std::string&` avoid copying a string?
4. What is the first thing to check when a compiler shows many errors?
5. Why is a one-loop counting algorithm O(n)?
6. Why is a two-nested-loop operation counter O(n²)?

## Answers

1. It provides standard input/output tools such as `std::cout` and `std::cin`.
2. It identifies a name from C++’s standard library namespace.
3. `&` passes a reference to the original string, and `const` prevents modification.
4. Read and fix the first reported error because later errors may be consequences of it.
5. It inspects each of the `n` values once.
6. The inner loop performs about `n` operations for each of about `n` outer-loop iterations.

## Optional completion checklist

- [ ] I understand `std::`, headers, strings, and the basic vector syntax used on Day 1.
- [ ] I fixed the deliberate compiler errors without copying the correction immediately.
- [ ] I completed one optional C++ practice program.
- [ ] I completed Count Even Numbers and explained its complexity.
