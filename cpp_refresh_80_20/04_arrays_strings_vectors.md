# Chapter 4 — Arrays, Strings and Vectors

**Time:** ~75 minutes  
**Goal:** Become fluent with sequence data, indexing, traversal, and common operations.

---

## 1. Raw arrays

A fixed-size array stores elements of the same type in contiguous memory.

```cpp
int a[5] = {10, 20, 30, 40, 50};
```

Indexes start at `0`:

```text
index:  0   1   2   3   4
value: 10  20  30  40  50
```

Access:

```cpp
std::cout << a[2]; // 30
```

### Bounds matter

For `int a[5]`, valid indexes are `0` through `4`.

```cpp
a[5] = 100; // invalid: outside the array
```

C++ usually does not protect you from this. That makes careful indexing very important in DSA.

---

## 2. Array traversal

```cpp
int a[] = {5, 8, 2, 9};
int n = 4;

for (int i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
}
```

The most common pattern is:

```cpp
for (int i = 0; i < n; ++i) {
    // use a[i]
}
```

Memorize the idea, not the characters:

> index starts at 0, stops before size.

---

## 3. `std::string`

```cpp
std::string s = "hello";
```

Indexing works similarly:

```cpp
std::cout << s[1]; // e
```

Length:

```cpp
std::cout << s.size();
```

Traversal:

```cpp
for (char c : s) {
    std::cout << c << ' ';
}
```

Strings can be modified:

```cpp
s[0] = 'H';
```

---

## 4. Useful string operations

Common operations:

```cpp
s.size()
s.empty()
s.push_back('!')
s.pop_back()
s.front()
s.back()
```

Substring:

```cpp
std::string t = s.substr(1, 3);
```

Find a substring:

```cpp
std::size_t pos = s.find("abc");
```

For basic DSA, you mostly need indexing, length, traversal, comparison, and modification.

---

## 5. `std::vector`

For DSA, `std::vector` is usually more useful than raw arrays.

```cpp
std::vector<int> a = {10, 20, 30};
```

Include:

```cpp
#include <vector>
```

Size:

```cpp
a.size()
```

Add an element:

```cpp
a.push_back(40);
```

Remove the last element:

```cpp
a.pop_back();
```

Access:

```cpp
a[1]
a.at(1)
```

For DSA, `a[i]` is the usual access method. `at()` performs bounds checking and can help during debugging.

---

## 6. Traversing vectors

Classic index-based traversal:

```cpp
for (int i = 0; i < static_cast<int>(a.size()); ++i) {
    std::cout << a[i] << ' ';
}
```

Range-based traversal:

```cpp
for (int x : a) {
    std::cout << x << ' ';
}
```

Modify elements:

```cpp
for (int& x : a) {
    x *= 2;
}
```

The `&` matters. Without it, `x` is a copy.

---

## 7. Passing vectors to functions

Read-only:

```cpp
int sum(const std::vector<int>& a) {
    int total = 0;
    for (int x : a) total += x;
    return total;
}
```

Modify:

```cpp
void doubleAll(std::vector<int>& a) {
    for (int& x : a) x *= 2;
}
```

Avoid this unless you specifically want a copy:

```cpp
int sum(std::vector<int> a) { ... }
```

Passing by value copies the vector.

---

## 8. Common sequence patterns

### Find maximum

```cpp
int best = a[0];
for (int x : a) {
    if (x > best) best = x;
}
```

### Count a condition

```cpp
int countEven = 0;
for (int x : a) {
    if (x % 2 == 0) ++countEven;
}
```

### Reverse in place

The standard library provides `std::reverse`, but implement it manually at least once.

```text
left --------> <-------- right
```

Swap while `left < right`.

---

# Hands-On Practice

## Arrays

### 1. Print an array

### 2. Sum all elements

### 3. Find minimum and maximum

### 4. Count positive, negative, and zero values

### 5. Count even numbers

### 6. Find the first occurrence of X

Return the index, or `-1` if not found.

### 7. Find the last occurrence of X

### 8. Reverse an array in place

### 9. Check whether an array is sorted

### 10. Find the second largest distinct value

Do not sort the array for the first version.

---

## Vector drills

### 11. Read N numbers into a vector

### 12. Sum and average

### 13. Remove all occurrences of X

Create a new vector first. Then attempt an in-place version.

### 14. Rotate right by one

Example:

```text
[1 2 3 4 5] -> [5 1 2 3 4]
```

### 15. Move all zeros to the end

Example:

```text
[0 1 0 3 12] -> [1 3 12 0 0]
```

Try to preserve the order of non-zero elements.

### 16. Merge two sorted vectors

Given:

```text
[1, 4, 8]
[2, 3, 9]
```

produce:

```text
[1, 2, 3, 4, 8, 9]
```

Do not simply sort the concatenation.

---

## String drills

### 17. Count vowels

### 18. Count uppercase/lowercase letters

### 19. Reverse a string

### 20. Check palindrome string

### 21. Count words

Assume words are separated by one or more spaces; think about how repeated spaces affect your logic.

### 22. Remove spaces

### 23. Toggle case

Convert lowercase letters to uppercase and uppercase letters to lowercase.

### 24. Character frequency

Given lowercase English letters, count the frequency of each character.

Try both:

```cpp
int freq[26] = {};
```

and later:

```cpp
std::unordered_map<char, int> freq;
```

---

# DSA Thinking Drill

For each of the following, write down:

1. input
2. output
3. one simple algorithm
4. time complexity
5. extra space

Problems:

- Find maximum in an array
- Check palindrome
- Count frequencies
- Move zeros to the end
- Merge two sorted arrays

Do this before coding.

---

# Chapter Checkpoint

You should be comfortable with:

- 0-based indexing
- array traversal
- vector creation and resizing
- `push_back` / `pop_back`
- passing vectors by reference
- modifying via `int&`
- string indexing and traversal
- basic frequency counting
- recognizing linear scans as O(n)
