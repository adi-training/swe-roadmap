# Chapter 3 — Functions, Scope, Modules and Errors

**Time:** ~60 minutes  
**Goal:** Learn to break solutions into reusable pieces and handle basic failures cleanly.

---

## 1. Functions

```python
def square(x):
    return x * x

print(square(7))
```

Parameters are local names inside the function.

```python
def add(a, b):
    return a + b
```

Call with positional or keyword arguments:

```python
add(2, 3)
add(a=2, b=3)
```

## 2. Default arguments

```python
def greet(name="friend"):
    return f"Hello, {name}!"
```

## 3. Scope

```python
x = 10

def demo():
    x = 20
    print(x)
```

The `x` inside `demo()` is local. Avoid using `global` unless you truly need shared module state.

## 4. Returning multiple values

Python packages multiple values into a tuple:

```python
def min_max(nums):
    return min(nums), max(nums)

lo, hi = min_max([4, 2, 9])
```

## 5. Modules

Put reusable code in a `.py` file and import it:

```python
import math
print(math.sqrt(25))
```

Common standard modules worth knowing:

```text
math
collections
itertools
sys
os
pathlib
```

You do not need to memorize every function. Know how to discover them.

## 6. Exceptions

A conversion can fail:

```python
try:
    n = int(input())
except ValueError:
    print("Please enter an integer")
```

Use exceptions for exceptional situations, not as a replacement for ordinary `if` logic.

## 7. `if __name__ == "__main__"`

This lets a file behave both as an importable module and as a runnable script:

```python
def main():
    print("Running program")

if __name__ == "__main__":
    main()
```

---

# Hands-on Exercises

## E1. `is_even`

Write a function returning `True` when a number is even.

## E2. `factorial`

Write a function that returns `n!` for non-negative `n`.

## E3. `is_prime`

Turn the prime check into a reusable function.

## E4. `count_vowels`

Write a function that counts vowels in a string.

## E5. Default greeting

Write `greet(name="friend")` returning a greeting string.

## E6. Min/max without built-ins

Write a function returning the smallest and largest element of a non-empty list without `min()` or `max()`.

## E7. Safe integer reader

Write a function that repeatedly asks for an integer until the user enters a valid integer.

## E8. Module exercise

Create `math_utils.py` with `square`, `cube`, and `is_even`. Create another script that imports and uses them.

## E9. Recursive factorial

Write recursive factorial and identify its base case.

## E10. Recursive sum

Write a recursive function that sums all integers from 1 through `n`.

