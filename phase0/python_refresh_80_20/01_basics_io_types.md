# Chapter 1 — Python Basics, Variables, Input/Output and Types

**Time:** ~45 minutes  
**Goal:** Become comfortable reading and writing small Python programs.

---

## 1. The shape of a Python program

```python
print("Hello, Python!")
```

Python uses indentation to define blocks. You normally do not need braces.

```python
name = "Maya"
age = 30

if age >= 18:
    print(name, "is an adult")
```

The four habits to build immediately are:

- use meaningful variable names
- keep indentation consistent
- read values from input when a problem is interactive
- print exactly what the problem asks for

## 2. Variables and basic types

```python
count = 10          # int
price = 19.5        # float
name = "Maya"       # str
active = True        # bool
nothing = None      # NoneType
```

Python variables are names bound to objects. You do not write the type in the variable declaration.

Check a type:

```python
print(type(count))
```

## 3. Input and conversion

`input()` always returns a string.

```python
age = int(input("Age: "))
height = float(input("Height: "))
name = input("Name: ")
```

A very common pattern:

```python
n = int(input())
nums = list(map(int, input().split()))
```

Read this as: split the line into strings, convert each string to `int`, then make a list.

## 4. Arithmetic

```python
+   -   *   /   //   %   **
```

Important differences:

```python
7 / 2   # 3.5
7 // 2  # 3
7 % 2   # 1
2 ** 3  # 8
```

## 5. String formatting

Prefer f-strings for simple output:

```python
name = "Maya"
score = 92
print(f"{name} scored {score}")
```

## 6. Comments

```python
# This is a comment.
```

Do not comment every obvious line. Comment the reason behind non-obvious code.

---

# Hands-on Exercises

## E1. Personal profile

Read a name, age, and city and print one sentence containing all three.

## E2. Rectangle calculator

Read length and width. Print area and perimeter.

## E3. Temperature conversion

Read Celsius and print Fahrenheit using `F = C * 9/5 + 32`.

## E4. Seconds converter

Read a number of seconds and print hours, minutes, and remaining seconds.

## E5. Swap values

Read two integers and print them after swapping.

## E6. Average of three numbers

Read three numbers and print their average to two decimal places.

## E7. Digit extraction

Read a positive integer and print its last digit and number of digits.

## E8. Simple bill

Read price and quantity, then print subtotal, 10% tax, and final total.

---
