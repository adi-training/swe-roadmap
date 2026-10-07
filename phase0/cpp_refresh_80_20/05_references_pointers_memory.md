# Chapter 5 — References, Pointers and Memory

**Time:** ~50 minutes  
**Goal:** Understand the practical pointer/reference knowledge needed for C++ and later DSA topics such as linked lists and trees.

---

## 1. Reference

A reference is another name for an existing object.

```cpp
int x = 10;
int& ref = x;

ref = 20;
```

Now `x` is also `20`.

Think:

```text
x  ─────┐
        ├── same object
ref ────┘
```

References are commonly used for function parameters:

```cpp
void increment(int& x) {
    ++x;
}
```

---

## 2. Pointer

A pointer stores an address.

```cpp
int x = 10;
int* p = &x;
```

`&x` means “address of x”.

`p` stores that address.

`*p` means “the object at the address stored in p”.

```cpp
std::cout << x << '\n';
std::cout << *p << '\n';
```

Both print `10`.

---

## 3. Changing through a pointer

```cpp
*p = 50;
```

Now `x` becomes `50`.

This is a key pointer idea:

```text
p  ----->  x
            50
```

---

## 4. `nullptr`

A pointer should not be left with an unknown garbage address.

Use:

```cpp
int* p = nullptr;
```

Before dereferencing a possibly-null pointer:

```cpp
if (p != nullptr) {
    std::cout << *p;
}
```

Dereferencing `nullptr` is invalid.

---

## 5. Pointer arithmetic

For an array:

```cpp
int a[] = {10, 20, 30};
int* p = a;
```

Then:

```cpp
*p       // 10
*(p + 1) // 20
*(p + 2) // 30
```

This is one reason arrays and pointers are closely related.

You do not need to master pointer arithmetic for modern DSA coding, but you should recognize it.

---

## 6. Arrays decay to pointers

When an array is passed to a function, it commonly becomes a pointer to the first element.

```cpp
void printArray(const int* a, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << ' ';
    }
}
```

Modern C++ DSA code usually prefers `std::vector` when the size can vary.

---

## 7. Dynamic memory

You may see:

```cpp
int* p = new int(42);
delete p;
```

For an array:

```cpp
int* a = new int[10];
delete[] a;
```

Important rule:

```text
new       -> delete
a new[]   -> delete[]
```

For modern C++, manual dynamic memory should usually be avoided unless there is a specific reason. Prefer `std::vector`, `std::string`, and smart pointers for ownership.

For DSA training, learn `new`/`delete` well enough to understand old or lower-level examples, but do not build your practice around them.

---

## 8. Stack vs heap: practical picture

You do not need a deep memory-model course yet. Remember the rough distinction:

- Local variables are typically automatic storage and live within their scope.
- Dynamically allocated objects have a different lifetime managed explicitly or by an owning object.
- Recursive calls use stack space.

The practical DSA lesson is:

> Know who owns an object, how long it should live, and whether you are copying it.

---

## 9. Reference vs pointer

Use a reference when:

- you expect an object to exist
- you want an alias to that object
- `nullptr` is not meaningful

Use a pointer when:

- an address-like relationship is part of the design
- `nullptr` is meaningful
- you need pointer-style manipulation

In linked lists and trees, pointers become central.

---

# Hands-On Practice

### 1. Change through reference

Write:

```cpp
void setToZero(int& x)
```

### 2. Change through pointer

Write:

```cpp
void setToZero(int* x)
```

Call it safely.

### 3. Swap through references

### 4. Swap through pointers

### 5. Find maximum using a pointer

Write a function taking `const int*` and a size.

### 6. Traverse an array with pointer arithmetic

Print all elements using a pointer rather than `a[i]`.

### 7. Sum through pointers

### 8. Reverse array using two pointers

Use one pointer at the beginning and one at the end.

### 9. Pointer safety test

Write a program that prints a value only if a pointer is non-null.

### 10. Dynamic array exercise

Allocate an array of N integers using `new[]`, fill it, print it, and release it with `delete[]`.

Then rewrite the same program using `std::vector` and compare the code.

---

# DSA Bridge Exercise

Later you may see a linked-list node like:

```cpp
struct Node {
    int value;
    Node* next;
};
```

Do not worry about implementing a full linked list yet.

Just answer:

- What is `value`?
- What is `next`?
- What does `Node*` mean?
- Why might `next` be `nullptr`?

Being able to answer these questions means the pointer refresher has done its job.

---

# Chapter Checkpoint

You should be able to explain:

- `&x`
- `int&`
- `int*`
- `*p`
- `nullptr`
- why references are common in function parameters
- why manual `new`/`delete` is usually avoided in ordinary modern C++ code
- why pointers matter for linked lists and trees
