# Chapter 1 — C++ Basics, Input/Output, Variables and Types

**Time:** ~45 minutes  
**Goal:** Become comfortable reading and writing small C++ programs.

---

## 1. The shape of a C++ program

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++!\n";
    return 0;
}
```

Important pieces:

- `#include <iostream>` gives access to console input/output.
- `main()` is where program execution starts.
- `{ ... }` defines a block.
- `std::cout` prints output.
- `\n` moves to the next line.
- `return 0;` indicates successful completion.

You will frequently see:

```cpp
using namespace std;
```

It lets you write `cout` instead of `std::cout`. For learning and DSA practice, either style is fine. Using `std::` makes it explicit where names come from.

---

## 2. Output with `cout`

```cpp
#include <iostream>

int main() {
    int age = 25;
    std::cout << "Age: " << age << "\n";
    std::cout << "Next year: " << age + 1 << "\n";
}
```

The `<<` operator sends values to the output stream.

---

## 3. Input with `cin`

```cpp
int age;
std::cin >> age;
```

Multiple values:

```cpp
int a, b;
std::cin >> a >> b;
```

Example:

```cpp
#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << "Sum = " << a + b << "\n";
}
```

### Reading a whole line

`cin >> name` stops at whitespace. Use `getline` when you want an entire line.

```cpp
std::string name;
std::getline(std::cin, name);
```

You need `<string>` for `std::string`.

A common beginner issue:

```cpp
int age;
std::cin >> age;
std::string name;
std::getline(std::cin, name); // may read the leftover newline
```

One fix is:

```cpp
std::cin.ignore();
std::getline(std::cin, name);
```

For DSA input, token-based `cin >>` is much more common.

---

## 4. Variables and basic types

A variable has a type and a value.

```cpp
int count = 10;
double price = 19.99;
char grade = 'A';
bool passed = true;
std::string name = "Ravi";
```

### Types worth remembering for DSA

| Type | Typical use |
|---|---|
| `int` | Counts, indexes, ordinary integers |
| `long long` | Larger integer values |
| `double` | Decimal calculations |
| `char` | One character |
| `bool` | True/false |
| `std::string` | Text |

### Integer overflow

Do not assume `int` can hold every possible integer.

```cpp
int x = 2'000'000'000;
// x * 2 may overflow
```

When values can become large, consider `long long`:

```cpp
long long x = 2'000'000'000LL;
```

The suffix `LL` marks a `long long` literal.

---

## 5. Constants

Use `const` when a value should not change.

```cpp
const double PI = 3.141592653589793;
```

This is useful for readability and prevents accidental reassignment.

---

## 6. Basic type conversion

```cpp
int a = 7;
int b = 2;
double result = static_cast<double>(a) / b;
```

Without the cast:

```cpp
double result = a / b; // integer division happens first
```

So:

```text
7 / 2       -> 3
7.0 / 2     -> 3.5
```

---

## 7. Arithmetic operators

```cpp
+   -   *   /   %
```

`%` gives the remainder.

```cpp
17 % 5  // 2
20 % 4  // 0
```

The remainder operator is extremely important in DSA for parity, divisibility, cyclic patterns, and digit problems.

---

## 8. A tiny mental model

Suppose:

```cpp
int x = 10;
x = x + 5;
```

Think:

```text
x initially stores 10
        ↓
read x → 10
        ↓
10 + 5 → 15
        ↓
store 15 in x
```

This simple model becomes very useful when tracing loops and arrays later.

---

# Hands-On Practice

## Warm-up programs

### 1. Hello profile

Read a name and age. Print:

```text
Hello <name>
You are <age> years old.
```

### 2. Rectangle calculator

Read length and width. Print area and perimeter.

### 3. Temperature converter

Read Celsius and print Fahrenheit.

Formula:

```text
F = C * 9 / 5 + 32
```

Be careful about integer division.

### 4. Simple interest

Read principal, rate, and time. Print simple interest.

### 5. Average of three numbers

Read three integers and print their average as a decimal.

### 6. Last digit

Read an integer and print its last digit.

Hint: `% 10`.

### 7. Sum of digits — two digit number

Read a two-digit integer and print the sum of its digits.

### 8. Seconds converter

Read a number of seconds and convert it to hours, minutes, and seconds.

### 9. Swap two values

Read two integers and swap them using a temporary variable.

### 10. Swap without a third variable

Repeat the previous exercise using arithmetic or `std::swap`. Prefer `std::swap` in real code, but understand the idea behind the exercise.

---

# Challenge Set

### Challenge A — Salary breakdown

Read a base salary and three percentage additions. Print the final salary.

### Challenge B — Digit extraction

Read a positive integer and print its hundreds, tens, and ones digits for a three-digit number.

### Challenge C — Expression prediction

Before running the following, predict the output:

```cpp
int a = 5;
int b = 2;
std::cout << a / b << "\n";
std::cout << a % b << "\n";
std::cout << static_cast<double>(a) / b << "\n";
```

### Challenge D — Type awareness

Create variables for:

- population
- product price
- first letter of a city
- whether a user is logged in
- user's full name

Choose an appropriate type for each.

---

# Chapter Checkpoint

You are ready to move on when you can explain without notes:

- What `main()` does
- Difference between `int` and `long long`
- Difference between `char` and `std::string`
- Why `7 / 2` is `3` with integers
- What `%` does
- Difference between `cin >> x` and `getline`
- Why a variable changes when you assign a new value
