# Chapter 6 — Structs, Classes and Constructors

**Time:** ~50 minutes  
**Goal:** Be comfortable defining simple custom data types, which is enough for many DSA implementations.

---

## 1. Why create your own type?

Suppose a student has:

```text
name
age
score
```

Keeping these as unrelated variables becomes messy. A `struct` groups related data.

```cpp
struct Student {
    std::string name;
    int age;
    double score;
};
```

Use it:

```cpp
Student s;
s.name = "Anita";
s.age = 20;
s.score = 91.5;
```

This is enough to understand many simple DSA node/data definitions.

---

## 2. `struct` vs `class`

In everyday beginner/DSA practice, the key difference to remember is the default access level:

- `struct` members are `public` by default.
- `class` members are `private` by default.

Example:

```cpp
struct Point {
    int x;
    int y;
};
```

versus:

```cpp
class Point {
private:
    int x;
    int y;
};
```

You can ignore advanced object-oriented design for this refresher. DSA mainly requires simple custom types and sometimes simple classes.

---

## 3. Member functions

A type can contain behavior as well as data.

```cpp
struct Rectangle {
    int width;
    int height;

    int area() const {
        return width * height;
    }
};
```

Use:

```cpp
Rectangle r{5, 3};
std::cout << r.area();
```

---

## 4. Constructors

A constructor initializes an object when it is created.

```cpp
class Point {
public:
    int x;
    int y;

    Point(int xValue, int yValue)
        : x(xValue), y(yValue) {}
};
```

Now:

```cpp
Point p(10, 20);
```

The part:

```cpp
: x(xValue), y(yValue)
```

is a member-initializer list.

Prefer initializing members this way.

---

## 5. `const` member functions

A member function that does not modify the object can be marked `const`:

```cpp
int area() const {
    return width * height;
}
```

This communicates intent and allows use with const objects.

---

## 6. DSA node pattern

A very important pattern is:

```cpp
struct Node {
    int data;
    Node* next;
};
```

Later, for trees:

```cpp
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};
```

At this stage, you only need to understand the shape.

---

# Hands-On Practice

### 1. `Point`

Create a `Point` struct with `x` and `y`.

Write a function that returns the Manhattan distance between two points:

```text
|x1 - x2| + |y1 - y2|
```

### 2. `Student`

Create a student struct and print the student with the highest score.

### 3. `Product`

Store name, price, and quantity. Calculate total inventory value.

### 4. `Book`

Store title, author, and year. Print books newer than a specified year.

### 5. `Rectangle`

Add `area()` and `perimeter()` methods.

### 6. Constructor practice

Create a `Point` class with a constructor.

### 7. `Counter`

Create a class containing an integer counter and methods:

```text
increment()
decrement()
get()
```

### 8. Simple node

Create a `Node` with an integer value and a `Node* next` pointer.

Create two nodes and connect them.

Print both values by following `next`.

### 9. Array of structs

Read N students into a `vector<Student>` and find the student with the highest score.

### 10. Sort-ready record

Define:

```cpp
struct Item {
    int id;
    int value;
};
```

Create a vector of `Item` and write a comparison function that orders items by `value`.

This prepares you for custom sorting in the STL chapter.

---

# Chapter Checkpoint

You should be able to:

- define a `struct`
- create and access members
- define simple member functions
- explain the basic difference between struct and class
- write a simple constructor
- read a linked-list/tree node declaration without confusion
