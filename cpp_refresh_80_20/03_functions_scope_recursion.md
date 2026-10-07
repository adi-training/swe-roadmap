# Chapter 3 — Functions, Scope and Recursion

**Time:** ~60 minutes  
**Goal:** Learn to break a program into reusable pieces and understand the basic idea behind recursion.

---

## 1. Why functions matter in DSA

A DSA solution should not become one giant `main()` function.

Functions help you:

- isolate logic
- test one idea at a time
- reuse code
- name an operation clearly
- reason about a solution

Example:

```cpp
int square(int x) {
    return x * x;
}

int main() {
    std::cout << square(7) << "\n";
}
```

A function has:

```text
return type
    ↓
int square(int x)
           ↑
       parameter
```

---

## 2. `void` functions

A function does not always return a value.

```cpp
void printHello() {
    std::cout << "Hello\n";
}
```

---

## 3. Parameters and arguments

```cpp
int add(int a, int b) {
    return a + b;
}
```

Here `a` and `b` are parameters. In:

```cpp
add(10, 20);
```

`10` and `20` are arguments.

---

## 4. Pass by value

```cpp
void change(int x) {
    x = 100;
}
```

Calling `change(a)` does **not** change the original `a` because `x` receives a copy.

Think:

```text
a = 10
  ↓ copy
x = 10
```

Changing `x` changes only the copy.

---

## 5. Pass by reference

```cpp
void change(int& x) {
    x = 100;
}
```

Now `x` refers to the caller's variable.

```cpp
int a = 10;
change(a);
// a is now 100
```

This is extremely important for DSA because references let functions modify vectors, counters, and other objects without copying them.

---

## 6. `const` reference

For a large object that a function should only read, a common pattern is:

```cpp
void printVector(const std::vector<int>& a) {
    for (int x : a) {
        std::cout << x << ' ';
    }
}
```

This avoids copying the vector and prevents the function from modifying it.

You will see this pattern constantly in C++ interview and DSA code.

---

## 7. Local and global scope

A variable declared inside a function/block is local to that scope.

```cpp
int main() {
    int x = 10;

    if (x > 0) {
        int y = 20;
        std::cout << y << '\n';
    }

    // y is not available here
}
```

Prefer local variables. Global state makes code harder to reason about.

---

## 8. Function declarations

A function can be defined before `main`, or declared first.

```cpp
int add(int a, int b);

int main() {
    std::cout << add(2, 3) << '\n';
}

int add(int a, int b) {
    return a + b;
}
```

The declaration tells the compiler the function exists.

---

## 9. Recursion: the basic idea

A recursive function calls itself.

Every useful recursive function needs:

1. a **base case** — when to stop
2. a **recursive step** — how the problem becomes smaller

Example:

```cpp
int factorial(int n) {
    if (n <= 1) {
        return 1; // base case
    }
    return n * factorial(n - 1); // recursive step
}
```

For `factorial(4)`:

```text
4 * factorial(3)
4 * 3 * factorial(2)
4 * 3 * 2 * factorial(1)
4 * 3 * 2 * 1
24
```

Do not memorize recursion. Learn to ask:

> What is the smallest version of the problem I already know how to solve?

---

## 10. Recursion and stack frames

Each recursive call gets its own local variables and return point.

This is why very deep recursion can cause stack overflow.

For DSA, recursion becomes important for trees, graphs, backtracking, divide-and-conquer, and dynamic programming. You only need the fundamentals here.

---

# Hands-On Practice

## Functions

### 1. `maxOfTwo`

Write a function returning the larger of two integers.

### 2. `isEven`

Return `true` if a number is even.

### 3. `isPrime`

Return whether a number is prime.

### 4. `gcd`

Write GCD as a function.

### 5. `power`

Write `power(base, exponent)` using a loop.

### 6. `countDigits`

Write a function that returns the number of digits.

### 7. `reverseNumber`

Return the reversed number.

### 8. `swap`

Write your own:

```cpp
void swapValues(int& a, int& b)
```

### 9. Array sum

Write:

```cpp
int sum(const std::vector<int>& a)
```

### 10. Count occurrences

Write a function that returns how many times `x` appears in a vector.

---

## Recursion drills

### 11. Factorial

Implement recursively.

### 12. Sum from 1 to N

Implement recursively.

### 13. Print 1 to N recursively

### 14. Print N to 1 recursively

### 15. Sum of digits recursively

### 16. Reverse a string recursively

Start with a function that prints characters from the end toward the beginning.

### 17. Fibonacci — naive recursion

Implement:

```text
fib(0) = 0
fib(1) = 1
fib(n) = fib(n-1) + fib(n-2)
```

Then ask: why is the naive recursive version slow?

Do not spend time optimizing it yet.

---

# Tiny Refactoring Exercise

Start with this idea:

```cpp
int main() {
    // read 5 numbers
    // find maximum
    // count even numbers
    // print results
}
```

Refactor it into at least three functions:

```text
read input
find maximum
count evens
```

The goal is not abstraction for its own sake. The goal is to make each piece easy to reason about.

---

# Chapter Checkpoint

You should be able to explain:

- Parameters vs arguments
- Pass-by-value vs pass-by-reference
- Why `const vector<int>&` is common
- Local scope
- Why functions improve DSA code
- Base case vs recursive step
- Why deep recursion uses stack space
