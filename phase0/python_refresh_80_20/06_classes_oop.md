# Chapter 6 — Classes and Practical OOP

**Time:** ~45 minutes  
**Goal:** Learn enough classes to read and write small object-oriented programs without turning the refresher into an OOP course.

---

## 1. Class and object

A class defines a shape and behavior. An object is an instance of that class.

```python
class Student:
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def passed(self):
        return self.score >= 40

s = Student("Maya", 85)
print(s.passed())
```

## 2. `self`

`self` refers to the current object. Instance attributes such as `self.name` belong to that object.

## 3. Class attributes

```python
class Dog:
    species = "Canis familiaris"
```

Use class attributes for data shared by instances. Do not accidentally use a mutable class attribute when you mean per-object state.

## 4. Inheritance

Know the syntax well enough to read simple code:

```python
class Animal:
    def speak(self):
        return "..."

class Dog(Animal):
    def speak(self):
        return "woof"
```

For DSA refresh, focus more on simple classes than inheritance-heavy design.

---

# Hands-on Exercises

## E1. Rectangle class

Create a `Rectangle` class with `area()` and `perimeter()`.

## E2. BankAccount

Create a class with `deposit`, `withdraw`, and `balance` state. Reject withdrawals larger than the balance.

## E3. Student class

Store name and marks and provide `average()` and `passed()` methods.

## E4. Counter

Create a `Counter` class with `increment`, `decrement`, and `value`.

## E5. Point

Create a `Point` class with a method returning Euclidean distance to another point.

## E6. Simple inheritance

Create `Animal` with `speak()`, and `Dog` and `Cat` that override it.

## E7. DSA node

Create a `Node` class with `value` and `next`, then manually link three nodes.

