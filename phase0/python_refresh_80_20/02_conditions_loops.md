# Chapter 2 — Conditions and Loops

**Time:** ~55 minutes  
**Goal:** Turn simple programs into programs that make decisions and repeat work.

---

## 1. Conditions

```python
x = 10

if x > 0:
    print("positive")
elif x == 0:
    print("zero")
else:
    print("negative")
```

Comparison operators:

```text
== != < > <= >=
```

Logical operators:

```text
and   or   not
```

Remember: `=` assigns; `==` compares.

## 2. Truthiness

Python lets many values act like true/false values.

Falsy examples:

```python
False
0
0.0
""
[]
{}
None
```

That makes patterns like this useful:

```python
if nums:
    print("not empty")
```

## 3. `for` loops

```python
for i in range(5):
    print(i)
```

This prints `0` through `4`.

Useful forms:

```python
range(5)          # 0,1,2,3,4
range(2, 7)       # 2..6
range(10, 0, -1)  # 10..1
```

Loop directly over values:

```python
for ch in "hello":
    print(ch)
```

## 4. `while`

Use `while` when repetition depends on a condition.

```python
x = 5
while x > 0:
    print(x)
    x -= 1
```

## 5. `break` and `continue`

```python
for x in range(10):
    if x == 7:
        break
```

`continue` skips the rest of the current iteration.

## 6. Nested loops

A loop inside a loop is often O(n²).

```python
for i in range(3):
    for j in range(3):
        print(i, j)
```

This pattern appears frequently in brute-force DSA solutions.

---

# Hands-on Exercises

## E1. Even or odd

Read an integer and print whether it is even or odd.

## E2. Largest of three

Read three integers and print the largest without using `max()`.

## E3. Grade

Read a score from 0–100 and print A/B/C/D/F using reasonable ranges.

## E4. Sum from 1 to n

Read `n` and compute the sum using a loop.

## E5. Count digits

Read a non-negative integer and count its digits using arithmetic and a loop.

## E6. Reverse an integer

Read an integer and print its digits reversed.

## E7. Multiplication table

Print the multiplication table of a number from 1 to 10.

## E8. Prime check

Read `n` and print whether it is prime.

## E9. Print primes

Read `n` and print every prime from 2 through `n`.

## E10. FizzBuzz

Print 1 to 100. Multiples of 3 become `Fizz`, multiples of 5 become `Buzz`, and multiples of both become `FizzBuzz`.

## E11. Fibonacci

Print the first `n` Fibonacci numbers using a loop, not recursion.

## E12. GCD

Implement Euclid's algorithm using a `while` loop.

