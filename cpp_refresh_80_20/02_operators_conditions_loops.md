# Chapter 2 — Operators, Conditions and Loops

**Time:** ~60 minutes  
**Goal:** Turn a simple program into a decision-making and repeated-computation program.

---

## 1. Comparison operators

```cpp
==   !=   <   >   <=   >=
```

The result is a `bool`.

```cpp
int x = 10;
std::cout << (x > 5);  // 1
```

When debugging, remember: `==` compares, `=` assigns.

```cpp
x = 5;      // assignment
x == 5;     // comparison
```

---

## 2. Logical operators

```cpp
&&   // AND
||   // OR
!    // NOT
```

Example:

```cpp
if (age >= 18 && age <= 60) {
    std::cout << "Working age range\n";
}
```

### Short-circuit evaluation

For `A && B`, if `A` is false, C++ does not need to evaluate `B`.

For `A || B`, if `A` is true, C++ does not need to evaluate `B`.

This matters later when checking indexes safely.

---

## 3. `if`, `else if`, `else`

```cpp
if (score >= 90) {
    std::cout << "A\n";
} else if (score >= 75) {
    std::cout << "B\n";
} else {
    std::cout << "C or below\n";
}
```

Conditions are evaluated from top to bottom.

---

## 4. `switch`

Use `switch` when you have discrete cases.

```cpp
int day;
std::cin >> day;

switch (day) {
    case 1:
        std::cout << "Monday\n";
        break;
    case 2:
        std::cout << "Tuesday\n";
        break;
    default:
        std::cout << "Invalid\n";
}
```

For most DSA problems, `if`/`else` is used more often, but `switch` is worth recognizing.

---

## 5. `for` loop

Use `for` when you know the loop structure clearly.

```cpp
for (int i = 0; i < 5; ++i) {
    std::cout << i << "\n";
}
```

Think of it as:

```text
initialize
check condition
run body
update
repeat
```

### Range-based `for`

Later, when working with containers:

```cpp
std::vector<int> a = {10, 20, 30};

for (int x : a) {
    std::cout << x << "\n";
}
```

---

## 6. `while` loop

Use `while` when the stopping condition is naturally expressed as a condition.

```cpp
int n;
std::cin >> n;

while (n > 0) {
    std::cout << n % 10 << "\n";
    n /= 10;
}
```

This pattern is particularly useful for digit-based problems.

---

## 7. `do-while`

The body runs at least once.

```cpp
int x;
do {
    std::cin >> x;
} while (x < 0);
```

It is less common in DSA but important to understand.

---

## 8. `break` and `continue`

`break` exits the loop.

```cpp
for (int i = 1; i <= 100; ++i) {
    if (i == 42) break;
}
```

`continue` skips the rest of the current iteration.

```cpp
for (int i = 1; i <= 10; ++i) {
    if (i % 2 == 0) continue;
    std::cout << i << " ";
}
```

Do not overuse them. Clear loop logic is usually easier to debug.

---

## 9. Nested loops

```cpp
for (int row = 0; row < 3; ++row) {
    for (int col = 0; col < 4; ++col) {
        std::cout << "* ";
    }
    std::cout << "\n";
}
```

A nested loop over `n` items often gives **O(n²)** work. This is the first important connection between syntax and complexity.

---

# Hands-On Practice

## Conditions

### 1. Even or odd

Read an integer and print whether it is even or odd.

### 2. Positive, negative, or zero

### 3. Largest of three

Read three numbers and print the largest.

### 4. Leap year

Determine whether a year is a leap year.

Use the standard divisibility rules.

### 5. Grade calculator

Convert a score into a grade using `if`/`else if`.

### 6. Triangle validity

Read three side lengths. Determine whether they can form a triangle.

### 7. Calculator with `switch`

Read two numbers and an operator (`+`, `-`, `*`, `/`). Perform the requested operation.

---

## Loop drills

### 8. Print 1 to N

### 9. Print N to 1

### 10. Sum 1 to N

Compute the sum using a loop.

Then write a second version using the mathematical formula.

### 11. Count digits

Read a positive integer and count its digits.

### 12. Reverse a number

Example:

```text
Input:  12340
Output: 4321
```

### 13. Palindrome number

Check whether an integer reads the same forwards and backwards.

### 14. Count even and odd digits

### 15. Sum of digits

### 16. Multiplication table

Print the multiplication table of a number from 1 to 10.

### 17. Prime check

Determine whether `n` is prime.

Start with the simple approach. Then optimize by checking only up to `sqrt(n)`.

### 18. Print primes in a range

Read `L` and `R`. Print all primes between them.

### 19. Greatest common divisor

Implement GCD using the Euclidean algorithm.

### 20. Pattern printing

Print:

```text
*
**
***
****
*****
```

Then print:

```text
*****
****
***
**
*
```

---

# Mini Debugging Drill

Find and fix the bug:

```cpp
int n;
std::cin >> n;

for (int i = 0; i <= n; ++i) {
    std::cout << i << "\n";
}
```

Is the program wrong? It depends on the intended range. Practice stating the intended values explicitly before fixing code.

Now inspect:

```cpp
int x = 5;
if (x = 10) {
    std::cout << "Ten\n";
}
```

The problem is assignment instead of comparison.

---

# Chapter Checkpoint

You should now be comfortable with:

- `==` vs `=`
- `&&`, `||`, `!`
- `if`/`else`
- `switch`
- `for` and `while`
- Nested loops
- `break` and `continue`
- Recognizing a likely O(n²) loop structure
- Tracing a loop by writing down the values of its variables
