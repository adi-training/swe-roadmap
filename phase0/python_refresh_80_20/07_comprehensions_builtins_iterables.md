# Chapter 7 — Comprehensions, Built-ins and Iterables

**Time:** ~55 minutes  
**Goal:** Learn the small set of Python features that makes solutions shorter without making them mysterious.

---

## 1. List comprehensions

Instead of:

```python
squares = []
for x in range(10):
    squares.append(x * x)
```

you can write:

```python
squares = [x * x for x in range(10)]
```

With a filter:

```python
evens = [x for x in range(20) if x % 2 == 0]
```

Do not force a comprehension when a normal loop is clearer.

## 2. Dictionary and set comprehensions

```python
sq = {x: x * x for x in range(5)}
unique_lengths = {len(word) for word in words}
```

## 3. `enumerate`

Instead of managing an index manually:

```python
for i, value in enumerate(nums):
    print(i, value)
```

## 4. `zip`

Iterate over related sequences together:

```python
names = ["A", "B"]
scores = [80, 90]
for name, score in zip(names, scores):
    print(name, score)
```

## 5. Useful built-ins

Know these well:

```text
len
sum
min
max
sorted
reversed
any
all
abs
enumerate
zip
range
```

## 6. `key=` and sorting

```python
words = ["pear", "apple", "kiwi"]
print(sorted(words, key=len))
```

For tuples:

```python
pairs = [(2, "b"), (1, "c"), (2, "a")]
print(sorted(pairs, key=lambda p: (p[0], p[1])))
```

Lambdas are small anonymous functions. Learn to read them; do not overuse them.

---

# Hands-on Exercises

## E1. Squares comprehension

Create a list of squares from 1 through 20 using a comprehension.

## E2. Filter positives

Given a list, make a list containing only positive values.

## E3. Enumerate positions

Print each value and its index using `enumerate`.

## E4. Zip names and scores

Build a dictionary from two lists using `zip`.

## E5. Longest string

Use `max(..., key=len)` to find the longest word.

## E6. Sort records

Sort a list of `(name, score)` tuples by score descending and name ascending.

## E7. Any/all

Given a list of numbers, use `any` to detect a negative number and `all` to check whether every number is positive.

## E8. Flatten one level

Given a list of lists, create one flat list using a comprehension.

## E9. Frequency dictionary comprehension

Given a list of words, build `{word: count}` using a normal dictionary and then express the final transformation as a comprehension.

